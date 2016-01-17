#include <iostream>
#include <cstdint>
#include <stdint.h>

using namespace std;

int main()
{
	size_t s;
	/*
	�y�A���C�����g�����߂�z

	s = alignof(int);
	VC2013�ł͂���alignof�̓T�|�[�g����Ă��Ȃ��̂�
	VC���Ǝ��ɃT�|�[�g���Ă���__alignof�ő�p�\
	*/
	/*
	C++�̊�{�^�w��
	bool
	char
	short
	int
	long
	long long
	float
	double
	long double
	wchar_t
	char16_t
	char32_t
	void
	*/
	//bool�̃A���C�����g
	s = __alignof(bool);
	cout << "bool��__alignof = " << s << endl;	//1
	/*char�̃A���C�����g*/
	s = __alignof(char);
	cout << "char��__alignof = " << s << endl;	//1
	/*short�̃A���C�����g*/
	s = __alignof(short);
	cout << "short��__alignof = " << s << endl;	//2
	/*int�̃A���C�����g*/
	s = __alignof(int);
	cout << "int��__alignof = " << s << endl;	//4
	/*long�̃A���C�����g*/
	s = __alignof(long);
	cout << "long��__alignof = " << s << endl;	//4
	/*long long�̃A���C�����g*/
	s = __alignof(long long);
	cout << "long long��__alignof = " << s << endl;	//8
	/*float�̃A���C�����g*/
	s = __alignof(float);
	cout << "float��__alignof = " << s << endl;	//4
	/*double�̃A���C�����g*/
	s = __alignof(double);
	cout << "double��__alignof = " << s << endl;	//8
	/*long double�̃A���C�����g*/
	s = __alignof(long double);
	cout << "long double��__alignof = " << s << endl;	//8
	/*wchar_t�̃A���C�����g*/
	s = __alignof(wchar_t);
	cout << "wchar_t��__alignof = " << s << endl;	//2
	/*char16_t�̃A���C�����g*/
	s = __alignof(char16_t);
	cout << "char16_t��__alignof = " << s << endl;	//2
	/*char32_t�̃A���C�����g*/
	s = __alignof(char32_t);
	cout << "char32_t��__alignof = " << s << endl;	//4
	/*
	C++11����傫�����w��ł��鐮���^����`���ꂽ
	<cstdint>,<stdint>�̃C���N���[�h���K�v
	std::�𖈉���邩using namespace std;�̐錾���K�v
	8bit��
	int8_t
	uint8_t
	16bit��
	int16_t
	uint16_t
	32bit��
	int32_t
	uint32_t
	64bit��
	int64_t
	uint64_t
	��������͏��Ȃ��Ƃ�����bit���ȏ゠�鐮���^
	8bit��
	int_least8_t
	uint_least8_t
	16bit��
	int_least16_t
	uint_least16_t
	32bit��
	int_least32_t
	uint_least32_t
	64bit��
	int_least64_t
	uint_least64_t
	��������͏��Ȃ��Ƃ�����bit���ȏ゠�鐮���^�ōł������ɉ��Z�ł���^
	8bit��
	int_fast8_t
	uint_fast8_t
	16bit��
	int_fast16_t
	uint_fast16_t
	32bit��
	int_fast32_t
	uint_fast32_t
	64bit��
	int_fast64_t
	uint_fast64_t
	���̏����n�ōő�̐����^
	intmax_t
	uintmax_t
	�L����void*�̒l��\���ł��鐮���^
	*/
	int8_t i8;
	uint8_t ui8;
	int16_t i16;
	uint16_t ui16;
	int32_t i32;
	uint32_t ui32;
	int64_t i64;
	uint64_t ui64;
	s = __alignof(int8_t);
	cout << "int8_t��__alignof = " << s << endl;	

	/*
	�y�A���C�����g���w�肷��z

	s = alignas(int)�͎g���Ȃ�
	__declspec(align(x))�ő�p
	*/

	struct SA{
		__declspec(align(4)) uint8_t a;
		__declspec(align(4)) uint16_t b;
		__declspec(align(4)) uint16_t c;
		//align(4)��4��4byte�ɃA���C�����g�����߂Ȃ����Ƃ��Ă���
		//bit���ł͂Ȃ��̂ŋC��t���邱��
		//__declspec(align(sizeof(int))) uint16_t b;�Ə����Ă�OK
	}sa;
	//4+4+4 = 12
	struct SB{
		uint8_t a;
		uint16_t b;
		uint16_t c;
	}sb;
	//1+2+2=5�̂͂��������ʂ�6�ƂȂ���
	//�����I�Ƀp�f�B���O�����������̂ƍl�����܂�
	cout << "sa " << sizeof(sa) << endl;
	cout << "sb " << sizeof(sb) << endl;
	
	/*
	Unicode�����񃊃e����
	VC2013���Ή�
	char16_t s16[] = u"deep";
	cout << s16 << endl;
	*/
	getchar();
}

