#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
�X���b�h���쐬����
*/
mutex printMutex;

void print(const string& s)
{
	lock_guard<mutex> lk(printMutex);
	cout << s.c_str() << endl;
}

void foo()
{
	print("main�Ƃ͕ʃX���b�h�ł�");
}

struct bar{
	void operator() (const string& msg,int x) const
	{
		print(msg + "���킽����܂���" + to_string(x));
	}
};

int main()
{
	thread th1(foo);	//������Thread����
	thread th2(bar(), "An argument",23);
	th1.join();
	th2.join();
	getchar();
	return 1;
}
