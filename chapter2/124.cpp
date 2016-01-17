#include <iostream>
/*
ラムダ式
[キャプチャ](仮引数リスト)->戻り値の型{複合文}
キャプチャの種類
[=]:全てのオブジエクトをコピーキャプチャ
[&]:全てのオブジエクトを参照キャプチャ
[v]:オブジエクトvをコピーキャプチャ
[&v]オブジエクトvを参照キャプチャ
[=,&v]:オブジエクトvを参照キャプチャ,それ以外はコピーキャプチャ
[&,v]:オブジエクトvをコピーキャプチャ、それ以外は参照キャプチャ

仮引数リスト　省略可
戻り値の型　省略可


*/
using namespace std;

void func()
{
	int x = 5;
	auto lamda = [x](int v)->int{return v * x; };
	cout << lamda(4) << endl;	//20が出力される

	auto lamda1 = [&x](int v)->int{return v * x; };
	cout << lamda1(41) << endl;	//205が出力される
}

int main()
{
	func();
	getchar();
	return 1;
}