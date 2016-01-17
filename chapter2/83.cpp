#include <iostream>

using namespace std;

/*
戻り値の型を後置きにできる
autoはなんのために置いている？
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