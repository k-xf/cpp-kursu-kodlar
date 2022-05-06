#include <mutex>
#include <syncstream>
#include <iostream>

std::mutex m1, m2;

void foo()
{
	while (1) {
		std::lock(m1, m2);

		m1.unlock();
		m2.unlock();
		std::osyncstream{ std::cout } << "foo()\n";
	}
}

void bar()
{
	while (1) {
		std::lock(m2, m1);

		m1.unlock();
		m2.unlock();
		std::osyncstream{ std::cout } << "bar()\n";
	}
}

int main()
{
	std::thread t1{ foo };
	std::thread t2{ bar};

	t1.join();
	t2.join();
}


