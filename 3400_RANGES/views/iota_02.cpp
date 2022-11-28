#include <iostream>
#include <ranges>

int main()
{
	auto v = std::views::iota(10);
	for (auto x : v | std::views::take(25))
		std::cout << x << ' '; // 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34
}
