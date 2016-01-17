#include <iostream>

/*
コンパイラアサート
*/
template<int Size>
struct Pool{
	static_assert(Size > 0, "プールサイズは0より大きくなければならない");
	char buffer[Size];
};

int main()
{
	Pool<10> pool;
	//Pool<0> pool1;	コンパイル時にアサートがでる

	getchar();
	return 1;
}