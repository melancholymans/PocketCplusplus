#include <iostream>
#include <typeinfo.h>
#include <vector>

using namespace std;

/*
�^�̎������_�Ǝ擾
*/
int foo()
{
	return 1;
}

int main()
{
	vector<int> v1(10);
	//auto���g��Ȃ����@
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		*it = 0;
	}
	//auto���g���ĕϐ��̐錾���ȗ��ɂȂ���
	int i = 0;
	for (auto it = v1.begin(); it != v1.end(); it++,i++){
		*it = i;
	}
	for (auto it = v1.begin(); it != v1.end(); it++){
		cout << *it << endl;
	}
	/*
	������^���擾
	decltype�͗^����ꂽ������^���擾�ł���
	*/
	decltype(foo()) v;
	cout << "decltype " << typeid(v).name() << endl;
	getchar();
	return 1;
}