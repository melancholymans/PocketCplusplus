#include <iostream>

using namespace std;

/*
VC2013���Ή�
*/
inline namespace inlineNamespace{
	void func();
}

void inlineNamespace::func()
{
	cout << "inline func" << endl;
}

int main()
{
	inlineNamespace::func();
	getchar();
	return 1;
}