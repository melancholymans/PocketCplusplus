#include <iostream>
#include <typeinfo>

using namespace std;


/*
可変長引数テンプレート
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
