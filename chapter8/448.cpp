#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
���s���s�ł���X���b�h�����擾����
*/
mutex Mutex;

void worker()
{
	/*
	�S���łP�Q��R�[�����ꂽ���̃p�\�R����CPU�R�A���Ɠ�����
	*/
	lock_guard<mutex> lk(Mutex);
	static int count = 0;
	cout << count << endl;
	count++;
}

int main()
{
	size_t mp = thread::hardware_concurrency();
	if (mp == 0){
		mp = 1;
	}

	vector<thread> ths(mp);
	for (thread& th : ths){
		th = thread(worker);
	}
	for (thread& th : ths){
		th.join();
	}
	getchar();
	return 1;
}
