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

	auto ft1 = std::async(std::launch::async, f, "first");
	auto ft2 = std::async(std::launch::async, f, "second");
	auto ft3 = std::async(std::launch::async, f, "third");

	ft1.get();
	ft2.get();
	ft3.get();
	auto tp_end = std::chrono::steady_clock::now();

	std::cout << dsec(tp_end - tp_start).count() << '\n';
}
