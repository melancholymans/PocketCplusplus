#include <iostream>
#include <cstdint>
#include <stdint.h>

using namespace std;

int main()
{
	size_t s;
	/*
	【アライメントを求める】

	s = alignof(int);
	VC2013ではこのalignofはサポートされていないので
	VCが独自にサポートしている__alignofで代用可能
	*/
	/*
	C++の基本型指定
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
	//boolのアライメント
	s = __alignof(bool);
	cout << "boolの__alignof = " << s << endl;	//1
	/*charのアライメント*/
	s = __alignof(char);
	cout << "charの__alignof = " << s << endl;	//1
	/*shortのアライメント*/
	s = __alignof(short);
	cout << "shortの__alignof = " << s << endl;	//2
	/*intのアライメント*/
	s = __alignof(int);
	cout << "intの__alignof = " << s << endl;	//4
	/*longのアライメント*/
	s = __alignof(long);
	cout << "longの__alignof = " << s << endl;	//4
	/*long longのアライメント*/
	s = __alignof(long long);
	cout << "long longの__alignof = " << s << endl;	//8
	/*floatのアライメント*/
	s = __alignof(float);
	cout << "floatの__alignof = " << s << endl;	//4
	/*doubleのアライメント*/
	s = __alignof(double);
	cout << "doubleの__alignof = " << s << endl;	//8
	/*long doubleのアライメント*/
	s = __alignof(long double);
	cout << "long doubleの__alignof = " << s << endl;	//8
	/*wchar_tのアライメント*/
	s = __alignof(wchar_t);
	cout << "wchar_tの__alignof = " << s << endl;	//2
	/*char16_tのアライメント*/
	s = __alignof(char16_t);
	cout << "char16_tの__alignof = " << s << endl;	//2
	/*char32_tのアライメント*/
	s = __alignof(char32_t);
	cout << "char32_tの__alignof = " << s << endl;	//4
	/*
	C++11から大きさが指定できる整数型が定義された
	<cstdint>,<stdint>のインクルードが必要
	std::を毎回つけるかusing namespace std;の宣言が必要
	8bit長
	int8_t
	uint8_t
	16bit長
	int16_t
	uint16_t
	32bit長
	int32_t
	uint32_t
	64bit長
	int64_t
	uint64_t
	ここからは少なくともそのbit長以上ある整数型
	8bit長
	int_least8_t
	uint_least8_t
	16bit長
	int_least16_t
	uint_least16_t
	32bit長
	int_least32_t
	uint_least32_t
	64bit長
	int_least64_t
	uint_least64_t
	ここからは少なくともそのbit長以上ある整数型で最も高速に演算できる型
	8bit長
	int_fast8_t
	uint_fast8_t
	16bit長
	int_fast16_t
	uint_fast16_t
	32bit長
	int_fast32_t
	uint_fast32_t
	64bit長
	int_fast64_t
	uint_fast64_t
	その処理系で最大の整数型
	intmax_t
	uintmax_t
	有効なvoid*の値を表現できる整数型
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
	cout << "int8_tの__alignof = " << s << endl;	

	/*
	【アライメントを指定する】

	s = alignas(int)は使えない
	__declspec(align(x))で代用
	*/

	struct SA{
		__declspec(align(4)) uint8_t a;
		__declspec(align(4)) uint16_t b;
		__declspec(align(4)) uint16_t c;
		//align(4)の4は4byteにアライメントを決めなさいとしている
		//bit数ではないので気を付けること
		//__declspec(align(sizeof(int))) uint16_t b;と書いてもOK
	}sa;
	//4+4+4 = 12
	struct SB{
		uint8_t a;
		uint16_t b;
		uint16_t c;
	}sb;
	//1+2+2=5のはずだが結果は6となった
	//自動的にパディングが入ったものと考えられます
	cout << "sa " << sizeof(sa) << endl;
	cout << "sb " << sizeof(sb) << endl;
	
	/*
	Unicode文字列リテラル
	VC2013未対応
	char16_t s16[] = u"deep";
	cout << s16 << endl;
	*/
	getchar();
}

