#include <iostream>
#include <typeinfo.h>
#include <vector>

using namespace std;

/*
Œ^‚Ì©“®„˜_‚Ææ“¾
*/
int foo()
{
	return 1;
}

int main()
{
	vector<int> v1(10);
	//auto‚ğg‚í‚È‚¢•û–@
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		*it = 0;
	}
	//auto‚ğg‚Á‚Ä•Ï”‚ÌéŒ¾‚ªŠÈ—ª‚É‚È‚Á‚½
	int i = 0;
	for (auto it = v1.begin(); it != v1.end(); it++,i++){
		*it = i;
	}
	for (auto it = v1.begin(); it != v1.end(); it++){
		cout << *it << endl;
	}
	/*
	®‚©‚çŒ^‚ğæ“¾
	decltype‚Í—^‚¦‚ç‚ê‚½®‚©‚çŒ^‚ğæ“¾‚Å‚«‚é
	*/
	decltype(foo()) v;
	cout << "decltype " << typeid(v).name() << endl;
	getchar();
	return 1;
}