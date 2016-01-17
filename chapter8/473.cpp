#include <iostream>
#include <mutex>
#include <thread>
#include <future>

using namespace std;

/*
スレッドをまたいで値や例外を渡す

エラーがでて実行できない？
*/

void worker(promise<int> p)
{
	try{
		//何か処理をして結果をpromiseに設定する
		p.set_value(1);
	}
	catch (exception& e){
		p.set_exception(current_exception());
	}
}

int main()
{
	promise<int> p;
	future<int> f = p.get_future();
	thread th(worker, move(p));
	try{
		cout << "value: " << f.get() << endl;
	}
	catch(exception& e){
		cout << "error: " << e.what() << endl;
	}
	th.join();
	getchar();
	return 1;
}
