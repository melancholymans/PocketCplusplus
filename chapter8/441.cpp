#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

/*
�X���b�h�������
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
	th.detach();	//�X���b�h�������
	cout << "bar end" << endl;
	getchar();
	th.join();		//�����ŗ�O���ł�̂�join�ő҂��󂯂͂ł��Ȃ�
	return 1;
}
