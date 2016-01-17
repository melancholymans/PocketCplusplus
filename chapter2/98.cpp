#include <iostream>

using namespace std;

struct S1{
	operator bool() const{
		return false;
	}
};

struct S2{
	explicit operator bool() const{
		return true;
	}
};
/*
operator ***()はクラスにある型変換演算子であるが
explicitをつけると暗黙的な型変換には応じませんという機能
*/
int main()
{
	S1 s1;
	bool a1(s1);			//明示的な変換
	cout << a1 << endl;

	bool a2 = bool(s1);		//明示的な変換
	cout << a2 << endl;

	bool a3 = s1;			//暗黙的な変換　OK
	cout << a3 << endl;

	S2 s2;
	bool b1(s2);			//明示的な変換
	cout << b1 << endl;

	bool b2 = bool(s2);		//明示的な変換
	cout << b2 << endl;

	//bool b3 = s2;			//暗黙的な変換　NG

	getchar();
}