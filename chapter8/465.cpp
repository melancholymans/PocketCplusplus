#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
�X���b�h�Z�[�t�ɂP�x�����֐����Ăяo��
*/

struct Object{
	Object() :data("�����������"){}	//�R���X�g���N�^�i���������X�g�Ń����o�[�ϐ���ݒ�j
	void initialize()
	{
		cout << "Object��������" << endl;
		data = "�������ς�";
		cout << "����������" << endl;
	}
	void print() const
	{
		lock_guard<mutex> lock(m);
		cout << data << endl;
	}
private:
	string data;
	/*
	�ʏ�const���\�b�h�ł͒l�̕ύX�͂ł��Ȃ���mutable��t�����ϐ��͕ύX�ł���
	mutable�́A�N���X��const�����o�֐�(���\�b�h)�̒��ł�����ł��郁���o�ϐ������ꍇ�Ɏw�肷��B
	*/
	mutable mutex m;
};

void initObj(Object& obj)
{
	obj.initialize();
}

void worker()
{
	/*
	���̊֐������ꂼ��̃X���b�h�ŌĂяo����邪�i�Q��jinitObj�֐���once_call�ŌĂяo���Ă���̂�
	�ŏ��̂P�񂵂����s����Ă��Ȃ�
	*/
	static once_flag f;
	static Object obj;
	call_once(f, initObj, ref(obj));
	obj.print();
}

int main()
{
	thread th1(worker);
	thread th2(worker);
	th1.join();
	th2.join();
	getchar();
	return 1;
}