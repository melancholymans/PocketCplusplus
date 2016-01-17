#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
スレッドを作成する
*/
mutex printMutex;

void print(const string& s)
{
	lock_guard<mutex> lk(printMutex);
	cout << s.c_str() << endl;
}

void foo()
{
	print("mainとは別スレッドです");
}

struct bar{
	void operator() (const string& msg,int x) const
	{
		print(msg + "がわたされました" + to_string(x));
	}
};

int main()
{
	thread th1(foo);	//ここでThread生成
	thread th2(bar(), "An argument",23);
	th1.join();
	th2.join();
	getchar();
	return 1;
}
