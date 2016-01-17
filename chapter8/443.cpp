#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
�X���b�h�����ʂ���
*/
mutex printMutex;

void foo()
{
	/*
	�����ŕ\�������id��VisualC++�̃c�[���o�[�ɕ\�����Ă���X���b�h�ԍ��Ɠ���
	*/
	lock_guard<mutex> lk(printMutex);
	cout << "foo" << this_thread::get_id() << endl;
}

void bar()
{
	/*
	�����ŕ\�������id��VisualC++�̃c�[���o�[�ɕ\�����Ă���X���b�h�ԍ��Ɠ���
	*/
	lock_guard<mutex> lk(printMutex);
	cout << "bar" << this_thread::get_id() << endl;
}


int main()
{
	/*
	�X���b�h��
	thread th1(foo)��foo�֐��ɔ��ł��������̂��Ƃǂ��ɕԂ��Ă���̂�
	�����Ăяo�����Ƃ���ɕԂ��Ă���̂Ȃ�
	cout << "main thread"�����C���X���b�h���܂߂ĂR��\�������͂��ł��邪�����ł͂Ȃ�
	���݂̂ł���������������id�͊ԈႢ�Ȃ�main thread�̂��ł�����
	���̂��Ƃ���thread�͍s�����炢�����܂�܂ł����Ŏd�������Ă��̊֐��ňꐶ���I����
	join�֐��͂�����Ăяo�������C���X���b�h���u���b�N���ČĂяo�����X���b�hth1,th2��
	�ꐶ���I����̂�҂��Ă���֐����Ǝv��

	*/
	thread th1(foo);
	thread th2(bar);
	cout << "main thread ?" << this_thread::get_id() << endl;	//������main�X���b�h��id���\�����ꂽ
	th1.join();
	th2.join();
	getchar();
	return 1;
}
