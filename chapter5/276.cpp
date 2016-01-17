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
	C++11は上のような初期化をサポートしているがVC++2013ではエラーがでるので
	array<int, 3> ar = { 1, 2, 3 };
	のようにする。
	*/
	array<int, 3> ar = { 1, 2, 3 };

	copy(ar.cbegin(), ar.cend(), ostream_iterator<int>(cout, "\n"));
	copy(ar.cbegin(), ar.cend(), ostream_iterator<int>(cout));
	cout << endl;
	/*
	C++11 固定長配列クラス std::array とは というサイトがあったので練習する
	http://vivi.dyndns.org/tech/cpp/array-container.html
	*/
	/*値の参照、代入*/
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
	/*メンバ関数*/
	/*
	empty()
	size()
	*/
	if (!ar3.empty()){
		printf("ar3 size = %d\n", ar3.size());
	}
	/*array の要素を取得*/
	/*
	front() : 先頭要素への参照を返す関数。
	back() : 末尾要素への参照を返す関数
	data() : 配列データ先頭アドレスを返す関数
	*/
	if (!ar3.empty()){
		auto f = ar3.front();
		printf("ar3 front = %d\n", ar3.front());
		printf("ar3 back = %d \n", ar3.back());
		printf("ar3 data address = %p \n", ar3.data());
		int* ptr = ar3.data();
		cout << *(ptr + 10) << endl;
	}
	/*array の状態を変更*/
	/*
	fill(値) : fill(値) は、array の全ての要素を指定した値にする関数。
	swap() : swap(オブジェクト名)」は引数で指定されたオブジェクトと内容を入れ替える関数
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
	/*その他のメンバ関数*/
	/*
	begin() : begin() は最初の要素へのイテレータ
	end() : end() は最後の要素の次へのイテレータを返します。
	cbegin() : begin() は最初の要素への const イテレータ
	cend() : cend() は最後の要素の次への const イテレータを返します。 
	*/
	int i = 0;
	for (auto it = v.begin(); it != v.end(); it++, i++){
		*it = i * 27;
	}
	for (auto it = v.begin(); it != v.end(); it++){
		cout << *it << endl;	
	}
	/*アルゴリズム*/
	/*
	accumulate()
		「accumulate(オブジェクト名.begin(), オブジェクト名.end(), init)」は、コンテナの最初から最後まで、要素を積算（全加算）するものだ。 最後の引数は初期値で、通常は0を指定する。
		なお、accumulate を利用するには「#include <numeric>」が必要。
	sort()
		「sort(オブジェクト名.begin(), オブジェクト名.end())」は、コンテナの要素を昇順にソートしてくれる関数だ。
		なお、sort を利用するには「#include <algorithm>」が必要。
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
	/*まとめ・参考*/
	/*
	std::array は、通常配列とまったく同じものに、std::vector にある便利な各種メンバ関数を追加したようなものだ。 
	それらを使用したい場合は、使うといいだろう。

	個人的には、array 型は要素数を省略できないので、void print(const array<int, > &ar) のような、
	関数を作ることが出来ないのはちょっと不満だ。
	固定長配列であっても vector を使ったとしてもたいした差はないので、現状では、常に vector を使う方がいいのではないかと考えている。
	*/
	getchar();
	return 0;
}

