#include <iostream>
#include <mutex>
#include <thread>
#include <future>

using namespace std;

/*
�X���b�h���܂����Œl���O��n��

�G���[���łĎ��s�ł��Ȃ��H
*/

void worker(promise<int> p)
{
	try{
		//�������������Č��ʂ�promise�ɐݒ肷��
		p.set_value(1);
	}
	catch (exception& e){
		p.set_exception(current_exception());
	}
}

int main()
{
	promise<int> p;
	future<int> f = p.get_future();
	thread th(worker, move(p));
	try{
		cout << "value: " << f.get() << endl;
	}
	catch(exception& e){
		cout << "error: " << e.what() << endl;
	}
	th.join();
	getchar();
	return 1;
}
