#include <thread>
#include <mutex>
#include <iostream>


std::recursive_mutex mtx;
int counter{};

void rfunc(int n)
{
	if (n == 0)
		return;

	mtx.lock();
	std::cout << "id = " << std::this_thread::get_id() << " cnt = " << ++counter << "\n";
	rfunc(n - 1);
	mtx.unlock();
}

int main()
{
	using namespace std;

	thread t1{ rfunc, 10 };
	thread t2{ rfunc, 10 };
	t1.join();
	t2.join();
}
