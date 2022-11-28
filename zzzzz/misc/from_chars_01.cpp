//https://en.cppreference.com/w/cpp/utility/from_chars

#include <iostream>
#include <charconv>
#include <array>


int main()
{
	std::array<char, 20> str{ "5487654123" };
	long long int result;
	if (auto[p, ec] = std::from_chars(str.data(), str.data() + str.size(), result); ec == std::errc())
		std::cout << result;
}
