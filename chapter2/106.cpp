#include <iostream>

/*
override,final
*/
using namespace std;

struct Base{
	virtual ~Base(){}
	virtual void print(string str){}
	virtual string input() { return " "; }
};

struct Derived :Base{
	void print(string str) override{ cout << "override: " << str.c_str() << endl; }
	string input() final{ return "final"; }
};

struct Derived1 :Derived{
	string input(){};		//オーバーライドできない
};

int main()
{
	Derived d;
	string str = d.input();
	d.print(str);
	getchar();
	return 1;
}