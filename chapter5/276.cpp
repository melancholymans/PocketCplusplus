#include <iostream>
#include <sstream>		//istringstream
#include <iterator>
#include <array>		//array
#include <numeric>
#include <algorithm>

using namespace std;

int main(void)
{
	/*
	array<int, 3> ar{ 1, 2, 3 };
	C++11�͏�̂悤�ȏ��������T�|�[�g���Ă��邪VC++2013�ł̓G���[���ł�̂�
	array<int, 3> ar = { 1, 2, 3 };
	�̂悤�ɂ���B
	*/
	array<int, 3> ar = { 1, 2, 3 };

	copy(ar.cbegin(), ar.cend(), ostream_iterator<int>(cout, "\n"));
	copy(ar.cbegin(), ar.cend(), ostream_iterator<int>(cout));
	cout << endl;
	/*
	C++11 �Œ蒷�z��N���X std::array �Ƃ� �Ƃ����T�C�g���������̂ŗ��K����
	http://vivi.dyndns.org/tech/cpp/array-container.html
	*/
	/*�l�̎Q�ƁA���*/
	const int SZ = 10;
	array<int, SZ> ar1 = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
	for (int i = 0; i < SZ; ++i){
		cout << ar1[i] << " ";
	}
	cout << endl;
	array<int, SZ> ar2;
	for (int i = 0; i < SZ; ++i){
		ar2[i] = i * 10;
	}
	for (int i = 0; i < SZ; ++i){
		cout << ar2[i] << " ";
	}
	cout << endl;

	array<int, 10000> ar3;
	for (int i = 0; i < 10000; ++i){
		ar3[i] = i + 1;
	}
	/*�����o�֐�*/
	/*
	empty()
	size()
	*/
	if (!ar3.empty()){
		printf("ar3 size = %d\n", ar3.size());
	}
	/*array �̗v�f���擾*/
	/*
	front() : �擪�v�f�ւ̎Q�Ƃ�Ԃ��֐��B
	back() : �����v�f�ւ̎Q�Ƃ�Ԃ��֐�
	data() : �z��f�[�^�擪�A�h���X��Ԃ��֐�
	*/
	if (!ar3.empty()){
		auto f = ar3.front();
		printf("ar3 front = %d\n", ar3.front());
		printf("ar3 back = %d \n", ar3.back());
		printf("ar3 data address = %p \n", ar3.data());
		int* ptr = ar3.data();
		cout << *(ptr + 10) << endl;
	}
	/*array �̏�Ԃ�ύX*/
	/*
	fill(�l) : fill(�l) �́Aarray �̑S�Ă̗v�f���w�肵���l�ɂ���֐��B
	swap() : swap(�I�u�W�F�N�g��)�v�͈����Ŏw�肳�ꂽ�I�u�W�F�N�g�Ɠ��e�����ւ���֐�
	*/
	ar3.fill(314);
	for (int i = 0; i < ar3.size(); i++){
		cout << ar3[i] << endl;
	}
	array<int, 10> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	array<int, 10>  z = {11,12,13,14,15,16,17,18,19,20};
	v.swap(z);
	for (int i = 0; i < v.size(); i++){
		cout << "v = " << v[i] << endl;
		cout << "z = " << z[i] << endl;
	}
	/*���̑��̃����o�֐�*/
	/*
	begin() : begin() �͍ŏ��̗v�f�ւ̃C�e���[�^
	end() : end() �͍Ō�̗v�f�̎��ւ̃C�e���[�^��Ԃ��܂��B
	cbegin() : begin() �͍ŏ��̗v�f�ւ� const �C�e���[�^
	cend() : cend() �͍Ō�̗v�f�̎��ւ� const �C�e���[�^��Ԃ��܂��B 
	*/
	int i = 0;
	for (auto it = v.begin(); it != v.end(); it++, i++){
		*it = i * 27;
	}
	for (auto it = v.begin(); it != v.end(); it++){
		cout << *it << endl;	
	}
	/*�A���S���Y��*/
	/*
	accumulate()
		�uaccumulate(�I�u�W�F�N�g��.begin(), �I�u�W�F�N�g��.end(), init)�v�́A�R���e�i�̍ŏ�����Ō�܂ŁA�v�f��ώZ�i�S���Z�j������̂��B �Ō�̈����͏����l�ŁA�ʏ��0���w�肷��B
		�Ȃ��Aaccumulate �𗘗p����ɂ́u#include <numeric>�v���K�v�B
	sort()
		�usort(�I�u�W�F�N�g��.begin(), �I�u�W�F�N�g��.end())�v�́A�R���e�i�̗v�f�������Ƀ\�[�g���Ă����֐����B
		�Ȃ��Asort �𗘗p����ɂ́u#include <algorithm>�v���K�v�B
	reverse()	
	*/

	array<int, 5> sum = { 2, 5, 78, 12, 43 };
	int total = accumulate(sum.begin(), sum.end(), 0);
	cout << "total " << total << endl;

	cout << "sort" << endl;
	sort(sum.begin(), sum.end());
	for (auto it = sum.begin(); it != sum.end(); it++){
		cout << *it << endl;
	}

	cout << "reverce" << endl;
	reverse(sum.begin(), sum.end());
	for (auto it = sum.begin(); it != sum.end(); it++){
		cout << *it << endl;
	}
	/*�܂Ƃ߁E�Q�l*/
	/*
	std::array �́A�ʏ�z��Ƃ܂������������̂ɁAstd::vector �ɂ���֗��Ȋe�탁���o�֐���ǉ������悤�Ȃ��̂��B 
	�������g�p�������ꍇ�́A�g���Ƃ������낤�B

	�l�I�ɂ́Aarray �^�͗v�f�����ȗ��ł��Ȃ��̂ŁAvoid print(const array<int, > &ar) �̂悤�ȁA
	�֐�����邱�Ƃ��o���Ȃ��̂͂�����ƕs�����B
	�Œ蒷�z��ł����Ă� vector ���g�����Ƃ��Ă������������͂Ȃ��̂ŁA����ł́A��� vector ���g�����������̂ł͂Ȃ����ƍl���Ă���B
	*/
	getchar();
	return 0;
}

