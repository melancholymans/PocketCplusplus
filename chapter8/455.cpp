#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
リソースのロックを管理する
*/

void foo(mutex& m)
{
	{
		lock_guard<mutex> lock(m);	//ここでロック
		this_thread::sleep_for(chrono::seconds(2));
	}	//スコープを抜けたらロック解除
	//ここはロックされていない
}

void bar(mutex& m, int n)
{
	unique_lock<mutex> ul(m, defer_lock);
	//この時点ではまだロックをかけていない
	for (;;){
		if (ul.try_lock()){
			cout << "ロック成功: " << n << endl;
			//時間のかかる処理
			this_thread::sleep_for(chrono::seconds(1));
			return;
		}
		else{
			this_thread::yield();
		}
	}
}

int main()
{
	mutex m;
	thread th1(foo, ref(m));
	thread th2(foo, ref(m));
	th1.join();
	th2.join();
	
	vector<thread> ths;
	for (int i = 0; i < 4; ++i){
		ths.push_back(thread(bar, ref(m), i));
	}
	for (thread& th:ths){
		th.join();
	}
	getchar();
	return 1;
}

