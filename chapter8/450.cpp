#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

/*
ƒXƒŒƒbƒh‚ğ”r‘¼§Œä‚·‚é
*/
struct Data{
	mutex mtx;
	int data;
};

/*
‚‚”‚˜‚Å”r‘¼§Œä‚µ‚Ä‚¢‚È‚¢‚Æ‚µ‚½‚Ì‚æ‚¤‚É‚È‚é
d.data : d.data : 1d.data : 1

d.data : 1
1
‚‚”‚˜‚Å”r‘¼§Œä‚µ‚Ä‚¢‚é‚Æ
d.data : 1
d.data : 2
d.data : 3
d.data : 4
‚Æ‚È‚é
*/
void worker(Data& d)
{
	d.mtx.lock();
	int n = d.data;
	{
		//ŠÔ‚Ì‚©‚©‚éŠÔ
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
