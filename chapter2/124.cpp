#include <iostream>
/*
�����_��
[�L���v�`��](���������X�g)->�߂�l�̌^{������}
�L���v�`���̎��
[=]:�S�ẴI�u�W�G�N�g���R�s�[�L���v�`��
[&]:�S�ẴI�u�W�G�N�g���Q�ƃL���v�`��
[v]:�I�u�W�G�N�gv���R�s�[�L���v�`��
[&v]�I�u�W�G�N�gv���Q�ƃL���v�`��
[=,&v]:�I�u�W�G�N�gv���Q�ƃL���v�`��,����ȊO�̓R�s�[�L���v�`��
[&,v]:�I�u�W�G�N�gv���R�s�[�L���v�`���A����ȊO�͎Q�ƃL���v�`��

���������X�g�@�ȗ���
�߂�l�̌^�@�ȗ���


*/
using namespace std;

void func()
{
	int x = 5;
	auto lamda = [x](int v)->int{return v * x; };
	cout << lamda(4) << endl;	//20���o�͂����

	auto lamda1 = [&x](int v)->int{return v * x; };
	cout << lamda1(41) << endl;	//205���o�͂����
}

int main()
{
	func();
	getchar();
	return 1;
}