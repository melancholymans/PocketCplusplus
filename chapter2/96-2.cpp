#include <iostream>

/*
�p���R���X�g���N�^
�h���N���X�Ŋ��N���X�̃R���X�g���N�^���Ăяo����@�\
VC++2013�ł͖��Ή�
*/
using namespace std;

struct Base{
	Base(int){ cout << "Base" << endl; }
};

struct Derived :Base{
	//Derived(){}
	using Base::Base;
};

int main()
{
	Derived d1;
	Derived d2(1);
}
