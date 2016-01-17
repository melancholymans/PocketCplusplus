#include <iostream>

using namespace std;

struct S1{
	operator bool() const{
		return false;
	}
};

struct S2{
	explicit operator bool() const{
		return true;
	}
};
/*
operator ***()�̓N���X�ɂ���^�ϊ����Z�q�ł��邪
explicit������ƈÖٓI�Ȍ^�ϊ��ɂ͉����܂���Ƃ����@�\
*/
int main()
{
	S1 s1;
	bool a1(s1);			//�����I�ȕϊ�
	cout << a1 << endl;

	bool a2 = bool(s1);		//�����I�ȕϊ�
	cout << a2 << endl;

	bool a3 = s1;			//�ÖٓI�ȕϊ��@OK
	cout << a3 << endl;

	S2 s2;
	bool b1(s2);			//�����I�ȕϊ�
	cout << b1 << endl;

	bool b2 = bool(s2);		//�����I�ȕϊ�
	cout << b2 << endl;

	//bool b3 = s2;			//�ÖٓI�ȕϊ��@NG

	getchar();
}