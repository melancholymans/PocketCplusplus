#include <iostream>

/*
継承コンストラクタ
派生クラスで基底クラスのコンストラクタを呼び出せる機能
VC++2013では未対応
*/
using namespace std;

struct Base{
	Base(int){ cout << "Base" << endl; }
};

struct Derived :Base{
	//Derived(){}
	using Base::Base;
};

int main()
{
	Derived d1;
	Derived d2(1);
}
