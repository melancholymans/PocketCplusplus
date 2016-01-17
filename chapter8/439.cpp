#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

/*
�X���b�h�̏I����ҋ@����
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
	thread th(foo);	//������Thread����
	th.join();
	print("�������I�����܂���");
	getchar();
	return 1;
}
