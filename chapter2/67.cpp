#include <iostream>

using namespace std;

int main()
{
	const char* str = "abc";
	const char* rstr = R"delimiter(abc)delimiter";
	cout << str << endl;
	cout << rstr << endl;
	getchar();
	return 1;
}