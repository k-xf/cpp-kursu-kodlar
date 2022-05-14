#include <mutex>

bool ready_flag;
std::mutex mtx;

void foo()
{
	std::lock_guard ulock(mtx);
	ready_flag = true;
}

void bar()
{
	
	{
		using namespace std::literals;

		std::unique_lock ulock(mtx);
		while (!ready_flag) {
			ulock.unlock();
			std::this_thread::yield(); 
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ulock.lock();
		}
	} 
	
	//...
}
