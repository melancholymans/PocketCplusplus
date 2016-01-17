#include <iostream>

using namespace std;
/*
class Base{
public:
	virtual ~Base(){};
};

class Derived1 :public Base {};
class Derived2 :public Base {};

template<class T>
void printType(const T& x)
{
	const type_info& type = typeid(x);
	if (type == typeid(Base)){
		cout << "Base" << endl;
	}
	else if (type == typeid(Derived1)){
		cout << "Derived1" << endl;
	}
	else if (type == typeid(Derived2)){
		cout << "Derived2" << endl;
	}
	else{
		cout << "unknow type" << endl;
	}
}

void func(int input)
{
	Base* p = nullptr;

	if (input == 0){
		p = new Derived1();
	}
	else{
		p = new Derived2();
	}
	printType(*p);
	delete p;
}

int main(void)
{
	func(0);
	func(1);
	getchar();
}
*/