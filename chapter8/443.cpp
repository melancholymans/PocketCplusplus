#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
スレッドを識別する
*/
mutex printMutex;

void foo()
{
	/*
	ここで表示されるidはVisualC++のツールバーに表示しているスレッド番号と同じ
	*/
	lock_guard<mutex> lk(printMutex);
	cout << "foo" << this_thread::get_id() << endl;
}

void bar()
{
	/*
	ここで表示されるidはVisualC++のツールバーに表示しているスレッド番号と同じ
	*/
	lock_guard<mutex> lk(printMutex);
	cout << "bar" << this_thread::get_id() << endl;
}


int main()
{
	/*
	スレッドは
	thread th1(foo)でfoo関数に飛んでいくがそのあとどこに返ってくるのか
	もし呼び出したところに返ってくるのなら
	cout << "main thread"がメインスレッドを含めて３回表示されるはずであるがそうではなく
	一回のみであったしかもそのidは間違いなくmain threadのもであった
	このことからthreadは行ったらいったまんまでそこで仕事をしてその関数で一生を終える
	join関数はこれを呼び出したメインスレッドをブロックして呼び出したスレッドth1,th2が
	一生を終えるのを待っている関数だと思う

	*/
	thread th1(foo);
	thread th2(bar);
	cout << "main thread ?" << this_thread::get_id() << endl;	//ここはmainスレッドのidが表示された
	th1.join();
	th2.join();
	getchar();
	return 1;
}
