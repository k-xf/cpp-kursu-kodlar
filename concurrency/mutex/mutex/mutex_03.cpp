#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std;


struct HasCriticalCode {
	//...
	std::mutex mx;
};


void func(HasCriticalCode& x, HasCriticalCode& y)
{
	x.mx.lock();
	this_thread::sleep_for(1ms);
	cout << "get the lock for the object at the address of " << &x << "\n";
	y.mx.lock();
	cout << "get the lock for the object at the address of " << &y << "\n";
	y.mx.unlock();
	x.mx.unlock();
}


int main()
{
	HasCriticalCode a, b;

	thread t1{ func, ref(a), ref(b) };
	thread t2{ func, ref(b), ref(a) };

	t1.join();
	t2.join();
}
