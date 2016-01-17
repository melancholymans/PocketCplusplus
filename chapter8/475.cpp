#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <future>

using namespace std;

/*
非同期処理をする
*/

int worker(const vector<int>& data)
{
	int sum = 0;
	for (int i : data){
		this_thread::sleep_for(chrono::milliseconds(100));
		sum += i;
	}
	return sum;
}

int main()
{
	vector<int> data = { 1, 2, 3, 4, 5 };
	/*
	ここでworker関数にスレッドを投げて計算が終わるまでまつ
	*/
	future<int> f = async(launch::async, worker, ref(data));
	/*
	worker関数が計算終了すればこのtry節に戻ってきて結果をf.get()で取得すことができる
	*/
	try{
		cout << f.get() << endl;
	}
	/*
	catch(...)は全ての例外をキャッチするという省略記号
	*/
	catch (...){
		cout << "all catch" << endl;
	}
	getchar();
	return 1;
}

