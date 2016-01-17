#include <iostream>
#include <string>

/*
文字列オブジェクトを構築する
*/

using namespace std;

int main()
{
	string a;
	string b = "sample";
	string c(b, 1, 3);
	string d("sample", 2);
	string e(10, 't');
	string f = { 's', 'a', 'm', 'p', 'l', 'e' };
	string g = b;
	string h0 = b;
	string h = move(h0);
	string i(b.begin(), b.end());
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;
	cout << "f: " << f << endl;
	cout << "g: " << g << endl;
	cout << "h: " << h << endl;
	cout << "i: " << i << endl;
	getchar();
	return 1;
}