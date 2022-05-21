#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>
#include <iostream>

class SpinLockMutex {
public:
	SpinLockMutex() 
	{
		m_f.clear(); 
	}
	void lock() 
	{
		while (!m_f.test_and_set())
			; //null statement
	}

	void unlock() 
	{
		m_f.clear();
	}
 private:
	std::atomic_flag m_f;
};

SpinLockMutex mtx;
unsigned long long counter{};

void func() 
{
	for (int i{ 0 }; i < 100'000; ++i) {
		mtx.lock();
		++counter;
		mtx.unlock();
	}
}

int main()
{
	std::vector<std::thread> tvec;

	for (int i = 0; i < 10; ++i) {
		tvec.emplace_back(func);
	}

	for (auto &th : tvec) {
		th.join();
	}

	std::cout << "counter = " << counter << "\n";
}
