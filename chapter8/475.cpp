#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <future>

using namespace std;

/*
�񓯊�����������
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
	������worker�֐��ɃX���b�h�𓊂��Čv�Z���I���܂ł܂�
	*/
	future<int> f = async(launch::async, worker, ref(data));
	/*
	worker�֐����v�Z�I������΂���try�߂ɖ߂��Ă��Č��ʂ�f.get()�Ŏ擾�����Ƃ��ł���
	*/
	try{
		cout << f.get() << endl;
	}
	/*
	catch(...)�͑S�Ă̗�O���L���b�`����Ƃ����ȗ��L��
	*/
	catch (...){
		cout << "all catch" << endl;
	}
	getchar();
	return 1;
}

