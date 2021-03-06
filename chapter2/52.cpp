#include <iostream>
#include <typeinfo.h>
#include <vector>

using namespace std;

/*
型の自動推論と取得
*/
int foo()
{
	return 1;
}

int main()
{
	vector<int> v1(10);
	//autoを使わない方法
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		*it = 0;
	}
	//autoを使って変数の宣言が簡略になった
	int i = 0;
	for (auto it = v1.begin(); it != v1.end(); it++,i++){
		*it = i;
	}
	for (auto it = v1.begin(); it != v1.end(); it++){
		cout << *it << endl;
	}
	/*
	式から型を取得
	decltypeは与えられた式から型を取得できる
	*/
	decltype(foo()) v;
	cout << "decltype " << typeid(v).name() << endl;
	getchar();
	return 1;
}