#include <iostream>
#include <typeinfo.h>

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
	/*
	h�͎����I��int�ƂƂȂ�Atypeid��int�^�Əo�͂���
	*/
	auto h = foo();
	cout << typeid(h).name() << endl;
	auto i1 = 1;
	const auto i2 = 2;
	cout << typeid(i2).name() << endl;
	static auto d = 3.0;
	cout << typeid(d).name() << endl;
	auto p1 = &i1;
	cout << typeid(p1).name() << endl;

	getchar();
}