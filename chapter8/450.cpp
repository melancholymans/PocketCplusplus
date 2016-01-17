#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
�X���b�h��r�����䂷��
*/
struct Data{
	mutex mtx;
	int data;
};

/*
�������Ŕr�����䂵�Ă��Ȃ��Ƃ����̂悤�ɂȂ�
d.data : d.data : 1d.data : 1

d.data : 1
1
�������Ŕr�����䂵�Ă����
d.data : 1
d.data : 2
d.data : 3
d.data : 4
�ƂȂ�
*/
void worker(Data& d)
{
	d.mtx.lock();
	int n = d.data;
	{
		//���Ԃ̂����鎞��
		this_thread::sleep_for(chrono::seconds(1));
		n += 1;
	}
	d.data = n;
	cout << "d.data : " << d.data << endl;
	d.mtx.unlock();
}

int main()
{
	vector<thread> ths(4);
	Data d;
	d.data = 0;
	for (thread& th : ths){
		th = thread(worker, ref(d));
	}
	for (thread& th : ths){
		th.join();
	}
	getchar();
	return 1;
}
