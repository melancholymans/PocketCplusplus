#include <iostream>
#include <vector>

using namespace std;

/*
エイリアステンプレート
using 新たな型名 = 元となる型名
*/
template <class T>
using Myvector = vector < T >;

int main()
{

	Myvector<int> v = { 1, 2, 3 };
	for (int x : v){
		cout << x << endl;
	}
	getchar();
	return 1;
}