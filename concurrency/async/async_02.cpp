#include <string>
#include <algorithm>
#include <thread>
#include <future>
#include <iostream>


std::string get_str_letters(int n)
{
	using namespace std::literals;

	std::string s(n, '\0');

	std::generate_n(s.begin(), n, [] {return rand() % 26 + 'A'; });
	std::this_thread::sleep_for(3s);

	return s;
}

//-------------------------------------------------------------------------------

std::string get_str_digits(int n)
{
	using namespace std::literals;

	std::string s(n, '\0');

	std::generate_n(s.begin(), n, [] {return rand() % 10 + '0'; });
	std::this_thread::sleep_for(3s);

	return s;
}

int main()
{
	auto start = std::chrono::steady_clock::now();

	auto ftr1 = async(std::launch::deferred, get_str_letters, 20);
	auto ftr2 = async(std::launch::deferred, get_str_digits, 20);

	//auto ftr1 = async(std::launch::async, get_str_letters, 20);
	//auto ftr2 = async(std::launch::async, get_str_digits, 20);


	auto s1 = ftr1.get();
	auto s2 = ftr2.get();
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double>(end - start).count() << " saniye\n";

	std::cout << s1 + s2 << "\n";
}
