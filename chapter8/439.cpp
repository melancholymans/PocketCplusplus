#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

/*
スレッドの終了を待機する
*/
mutex printMutex;
template<class T>
void print(T x)
{
	lock_guard<mutex> lk(printMutex);
	cout << x << endl;
}

void foo()
{
	for (int i = 0; i < 3; ++i){
		print(i);
	}
}

int main()
{
	thread th(foo);	//ここでThread生成
	th.join();
	print("処理が終了しました");
	getchar();
	return 1;
}
