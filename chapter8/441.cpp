#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

/*
スレッドを手放す
*/

void foo()
{
	chrono::seconds d(30);
	this_thread::sleep_for(d);	//30 sec
	cout << "foo end" << endl;
}


int main()
{
	thread th(foo);
	th.detach();	//スレッドを手放す
	cout << "bar end" << endl;
	getchar();
	th.join();		//ここで例外がでるのでjoinで待ち受けはできない
	return 1;
}
