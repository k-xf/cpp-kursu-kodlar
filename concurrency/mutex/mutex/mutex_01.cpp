#include <thread>
#include <mutex>
#include <iostream>

unsigned long long counter = 0;
std::mutex mtx;

void func()
{
	//mtx.lock();
	for (unsigned long long i = 0; i < 1'000'000; ++i) {
		++counter;
	}
	//mtx.unlock();
}

int main()
{
	std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);
	std::thread t4(func);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	std::cout << counter << '\n';
}
