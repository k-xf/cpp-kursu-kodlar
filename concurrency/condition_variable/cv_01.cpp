#include <iostream>
#include <mutex>

int shared_variable = 0;
std::mutex mtx;

void producer()
{
	using namespace std::literals;
	std::this_thread::sleep_for(1000ms);
	std::lock_guard lg{ mtx };
	shared_variable = 999;
}


void consumer()
{
	std::unique_lock ulock{ mtx};
	while (shared_variable == 0) {
		ulock.unlock();
		ulock.lock();
	}

	std::cout << "value is " << shared_variable << "\n";
}

int main()
{
	std::thread t1{ producer };
	std::thread t2{ consumer };

	t1.join();
	t2.join();
}
