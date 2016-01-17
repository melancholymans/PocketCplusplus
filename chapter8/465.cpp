#include <iostream>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

/*
スレッドセーフに１度だけ関数を呼び出す
*/

struct Object{
	Object() :data("未初期化状態"){}	//コンストラクタ（初期化リストでメンバー変数を設定）
	void initialize()
	{
		cout << "Objectを初期化" << endl;
		data = "初期化済み";
		cout << "初期化完了" << endl;
	}
	void print() const
	{
		lock_guard<mutex> lock(m);
		cout << data << endl;
	}
private:
	string data;
	/*
	通常constメソッドでは値の変更はできないがmutableを付けた変数は変更できる
	mutableは、クラスのconstメンバ関数(メソッド)の中でも操作できるメンバ変数を作る場合に指定する。
	*/
	mutable mutex m;
};

void initObj(Object& obj)
{
	obj.initialize();
}

void worker()
{
	/*
	この関数をそれぞれのスレッドで呼び出されるが（２回）initObj関数はonce_callで呼び出しているので
	最初の１回しか実行されていない
	*/
	static once_flag f;
	static Object obj;
	call_once(f, initObj, ref(obj));
	obj.print();
}

int main()
{
	thread th1(worker);
	thread th2(worker);
	th1.join();
	th2.join();
	getchar();
	return 1;
}