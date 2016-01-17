#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
複数のリソースのロックする
*/

struct Data{
	mutex m;
	int data;
	Data() :data(0){}	//コストラクラ
};

void foo(Data& d1,Data& d2)
{
	unique_lock<mutex> u1(d1.m, defer_lock);
	unique_lock<mutex> u2(d2.m, defer_lock);
	lock(u1, u2);
	d1.data += 1;
	d2.data = d2.data + d1.data;
}

int main()
{
	Data d1, d2;
	thread th1(foo, ref(d1), ref(d2));
	thread th2(foo, ref(d1), ref(d2));
	th1.join();
	th2.join();
	cout << d2.data << endl;
	getchar();
	return 1;
}