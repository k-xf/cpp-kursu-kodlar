#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <algorithm>
#include <future>


int main()
{
	std::cout << "number od supported threads: " << std::thread::hardware_concurrency() << "\n";
	std::cout << "how many integers: ";
	int n; std::cin >> n;

	//std::future<std::vector<int>> vec_future = std::async(std::launch::async, [n]() {
	auto vec_future = async(std::launch::async, [n]() {
		std::vector<int> ivec(n);
		std::generate_n(ivec.begin(), n, rand);
		std::cout << "greetings from thread with the id of " << std::this_thread::get_id() << '\n';
		std::cout << "address of the dynamic array is: " << ivec.data() << "\n";
		return ivec;
		});

	auto vec = vec_future.get();
	std::cout << "greetings from thread with the id of " << std::this_thread::get_id() << '\n';
	std::cout << "address of the dynamic array is: " << vec.data() << "\n";
	std::cout << "vec.size() = " << vec.size() << "\n";


	std::future<double> mean_future = async(std::launch::async, [&vec]() {
		std::cout << std::this_thread::get_id() << " id'li thread'den selamlar\n";
		return std::accumulate(vec.begin(), vec.end(), 0) / static_cast<double>(vec.size());
		});

	const auto mean = mean_future.get();
	std::cout << "ortalama : " << mean;
}
