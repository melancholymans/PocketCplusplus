#include <iostream>

using namespace std;

/*
�߂�l�̌^����u���ɂł���
auto�͂Ȃ�̂��߂ɒu���Ă���H
*/

auto power(int x, int n)->int
{
	int ret = 1;
	for (int i = 0; i < n; i++) ret *= x;
	return ret;
}

int main()
{
	cout << power(2, 3) << endl;
	getchar();
	return 1;
}