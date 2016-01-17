#include <iostream>
#include <typeinfo>

using namespace std;


/*
�ϒ������e���v���[�g
*/

void printType()
{
	cout << endl;
}

template <class Thread,class... Tbody>
void printType(Thread head, Tbody... body)
{
	cout << '(' << typeid(Thread).name() << ')' << head;
	if (sizeof...(body) > 0) cout << ',';
	printType(body...);
}

int main()
{
	printType('T', 4, "tow");
	getchar();
	return 1;
}
