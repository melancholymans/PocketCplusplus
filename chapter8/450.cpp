#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
スレッドを排他制御する
*/
struct Data{
	mutex mtx;
	int data;
};

/*
ｍｔｘで排他制御していないとしたのようになる
d.data : d.data : 1d.data : 1

d.data : 1
1
ｍｔｘで排他制御していると
d.data : 1
d.data : 2
d.data : 3
d.data : 4
となる
*/
void worker(Data& d)
{
	d.mtx.lock();
	int n = d.data;
	{
		//時間のかかる時間
		this_thread::sleep_for(chrono::seconds(1));
		n += 1;
	}
	d.data = n;
	cout << "d.data : " << d.data << endl;
	d.mtx.unlock();
}

int main()
{
	vector<thread> ths(4);
	Data d;
	d.data = 0;
	for (thread& th : ths){
		th = thread(worker, ref(d));
	}
	for (thread& th : ths){
		th.join();
	}
	getchar();
	return 1;
}
