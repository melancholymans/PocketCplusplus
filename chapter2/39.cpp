#include <iostream>

/*
スコープ付き列挙型
列挙型の型を指定
*/

using namespace std;

int main()
{
	/*
	スコープ付き列挙型
	*/
	int blue;
	//enum TrafficLight { blue, yellow, red };	blue変数の再定義とエラーがでる
	enum struct TrafficLight  { blue, yellow, red };	//こっちはOK
	TrafficLight color = TrafficLight::yellow;			//こう使う
	cout << int(color) << endl;							//cout << color << endlとすると << に対する演算子がないといわれる
	/*
	列挙型の型を指定
	*/
	enum struct singou:unsigned long  { blue, yellow, red };	//こっちはOK
	cout << typeid(singou::red).name() << endl;					//うまく表示されない
	cout << typeid(blue).name() << endl;

	getchar();
	return 1;
}
