#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
���\�[�X�̃��b�N���Ǘ�����
*/

void foo(mutex& m)
{
	{
		lock_guard<mutex> lock(m);	//�����Ń��b�N
		this_thread::sleep_for(chrono::seconds(2));
	}	//�X�R�[�v�𔲂����烍�b�N����
	//�����̓��b�N����Ă��Ȃ�
}

void bar(mutex& m, int n)
{
	unique_lock<mutex> ul(m, defer_lock);
	//���̎��_�ł͂܂����b�N�������Ă��Ȃ�
	for (;;){
		if (ul.try_lock()){
			cout << "���b�N����: " << n << endl;
			//���Ԃ̂����鏈��
			this_thread::sleep_for(chrono::seconds(1));
			return;
		}
		else{
			this_thread::yield();
		}
	}
}

int main()
{
	mutex m;
	thread th1(foo, ref(m));
	thread th2(foo, ref(m));
	th1.join();
	th2.join();
	
	vector<thread> ths;
	for (int i = 0; i < 4; ++i){
		ths.push_back(thread(bar, ref(m), i));
	}
	for (thread& th:ths){
		th.join();
	}
	getchar();
	return 1;
}

