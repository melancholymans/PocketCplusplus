#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
現在のスレッドをスリープする
*/

mutex printMutex;

void print(const string& func,int value)
{
	lock_guard<mutex> lk(printMutex);
	cout << func.c_str() << " : " << value << endl;
}

void foo()
{
	chrono::seconds d(1);

	for (int i = 0; i < 3; ++i){
		print("foo()", i);
		this_thread::sleep_for(d);
	}
}

void bar()
{
	chrono::system_clock::time_point t = chrono::system_clock::now();
	for (int i = 0; i < 3; ++i){
		print("bar()", i);
		this_thread::sleep_until(t + chrono::seconds(i + 1));
	}
}

int main()
{
	thread th1(foo);
	thread th2(bar);
	th1.join();
	th2.join();
	
	getchar();
	return 1;
}