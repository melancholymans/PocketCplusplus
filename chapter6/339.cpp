#include <iostream>
#include <tuple>

using namespace std;

int main(void)
{
	tuple<int, char,string> p(1,'W', "hello");
	cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p).c_str() << endl;
	/*
	‚±‚¤‚Í‚Å‚«‚È‚¢
	for (int i = 0; i < 3; i++){
		cout << get<i>(p) << endl;
	}
	*/
	getchar();
}
