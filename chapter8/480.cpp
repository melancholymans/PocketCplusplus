#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <
using namespace std;

/*
スレッドローカル変数を使用する
未実装
*/

static mutex mtx;

void bar(int n)
{
	static int sn = 0;
	__declspec(thread) int tn = 1;	//スレッド
}
