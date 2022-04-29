#include <mutex>
#include <iostream>

std::mutex m;

int main()
{
	std::unique_lock<std::mutex> guard{ m, std::defer_lock};
	if (guard) {
		std::cout << "owns a lock\n";
	}
	else {
		std::cout << "doesn't own a lock\n";
	}

	guard.lock();

	if (guard) {
		std::cout << "owns a lock\n";
	}
	else {
		std::cout << "doesn't own a lock\n";
	}
}
