#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <
using namespace std;

/*
�X���b�h���[�J���ϐ����g�p����
������
*/

static mutex mtx;

void bar(int n)
{
	static int sn = 0;
	__declspec(thread) int tn = 1;	//�X���b�h
}
