#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

using namespace std;

/*
ロックせず排他アクセスする
*/

int x;
atomic<bool> ay;

void foo()
{
	x = 10;
	ay.store(true, memory_order_release);
}

void bar()
{
	bool y;
	do{
		y = ay.load(memory_order_acquire);
	} while (!y);
	cout << x << endl;
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

