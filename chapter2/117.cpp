#include <iostream>
#include <vector>

using namespace std;

/*
�G�C���A�X�e���v���[�g
using �V���Ȍ^�� = ���ƂȂ�^��
*/
template <class T>
using Myvector = vector < T >;

int main()
{

	Myvector<int> v = { 1, 2, 3 };
	for (int x : v){
		cout << x << endl;
	}
	getchar();
	return 1;
}