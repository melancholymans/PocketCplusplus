#include <iostream>		//cin,cout
#include <memory>		//unique_ptr

using namespace std;
/*
class X{
public:
	void foo()
	{
		cout << "this foo" << endl;
	}
	void bar()
	{
		cout << "this bar" << endl;
	}
};
�J�X�^���J���֐��̎w�肪���܂������Ȃ�
void custom_delete_func(int *i)
{
	cout << "this time is delete" << endl;
}

int main(void)
{
	{
		unique_ptr<X,void(int*)> p(new X,custom_delete_func);
		p->bar();
	}
	cout << "getchar" << endl;
	getchar();
	return 0;
}
*/
