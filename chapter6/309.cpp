#include <iostream>

/*
�R���p�C���A�T�[�g
*/
template<int Size>
struct Pool{
	static_assert(Size > 0, "�v�[���T�C�Y��0���傫���Ȃ���΂Ȃ�Ȃ�");
	char buffer[Size];
};

int main()
{
	Pool<10> pool;
	//Pool<0> pool1;	�R���p�C�����ɃA�T�[�g���ł�

	getchar();
	return 1;
}