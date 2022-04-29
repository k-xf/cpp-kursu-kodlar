#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <shared_mutex>
#include <fstream>

std::mutex file_mutex;
int counter = 0;
std::shared_mutex counter_mutex;
std::ofstream ofs{ "out.txt" };

void func_writer()
{
	using namespace std::literals;
	for (int i{}; i < 10; ++i) {
		{
			//std::scoped_lock<std::shared_mutex> lock(counter_mutex);
			std::scoped_lock lock(counter_mutex); //CTAD
			++counter;
		}
		std::this_thread::sleep_for(150ms);
	}
}

void foo_reader()
{
	for (int i = 0; i < 100; ++i) {
		int c;
		{
			//std::shared_lock<std::shared_mutex> lock(counter_mutex);
			std::shared_lock lock(counter_mutex); //CTAD
			c = counter;
		}
		{
			std::scoped_lock lock(file_mutex);
			ofs << std::this_thread::get_id() << ' ' << c << '\n';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

int main()
{
	if (!ofs) {
		std::cerr << "out.txt dosyasi olusturulamadi\n";
		exit(EXIT_FAILURE);
	}

	std::vector<std::jthread> threads;
	threads.emplace_back(&func_writer);
	for (int i{}; i < 8; ++i)
		threads.emplace_back(&foo_reader);
}
