#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
並行実行できるスレッド数を取得する
*/
mutex Mutex;

void worker()
{
	/*
	全部で１２回コールされたこのパソコンのCPUコア数と同じ数
	*/
	lock_guard<mutex> lk(Mutex);
	static int count = 0;
	cout << count << endl;
	count++;
}

int main()
{
	size_t mp = thread::hardware_concurrency();
	if (mp == 0){
		mp = 1;
	}

	vector<thread> ths(mp);
	for (thread& th : ths){
		th = thread(worker);
	}
	for (thread& th : ths){
		th.join();
	}
	getchar();
	return 1;
}
