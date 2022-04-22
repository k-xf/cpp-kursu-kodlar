#include <chrono>
#include <future>
#include <iostream>
#include <thread>

int main() 
{
	using namespace std::literals;
	using dsec = std::chrono::duration<double>;

	auto f = [](const std::string& name) {
		std::cout << name << std::endl;
		std::this_thread::sleep_for(3s);
	};

	auto tp_start = std::chrono::steady_clock::now();

	std::async(f, "first");
	std::async(f, "second");
	std::async(f, "third");

	auto tp_end = std::chrono::steady_clock::now();

	std::cout << dsec(tp_end - tp_start).count() << '\n';
}
