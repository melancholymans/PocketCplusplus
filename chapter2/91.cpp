#include <iostream>

using namespace std;

/*
非静的メンバー変数の定義箇所での初期化
C++１１の前はできなかったの？
*/

struct AnswerSheet{
	int age = -1;
	int answer = 0;
};

int main()
{
	AnswerSheet as;
	cout << as.age << " " << as.answer << endl;
	getchar();
	return 1;
}


