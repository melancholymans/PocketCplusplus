#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <deque>
#include <condition_variable>

using namespace std;

/*
ğŒ•Ï”‚ğg—p‚·‚é
*/

template <class T>
struct LockedQueue{
	explicit LockedQueue(int capacity) :capacity(capacity){}

	void enqueue(const T& x)
	{
		unique_lock<mutex> lock(m);
		c_enq.wait(lock, [this] {return data.size() != capacity; });
		data.push_back(x);
		c_deq.notify_one();
	}
	T dequeue()
	{
		unique_lock<mutex> lock(m);
		c_deq.wait(lock, [this] {return !data.empty(); });
		T ret = data.front();
		data.pop_front();
		c_enq.notify_one();
		return ret;
	}
	private:
		mutex m;
		deque<T> data;
		size_t capacity;
		condition_variable c_enq;
		condition_variable c_deq;
};

void worker(LockedQueue<int>& lq)
{
	for (int i = 0; i < 5; ++i){
		lq.enqueue(i);
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
	LockedQueue<int> lq(2);
	thread th(worker, ref(lq));
	this_thread::sleep_for(chrono::milliseconds(1000));
	for (int i = 0; i < 5; ++i){
		int n = lq.dequeue();
		cout << "poped: " << n << endl;
	}
	getchar();
	return 1;
}