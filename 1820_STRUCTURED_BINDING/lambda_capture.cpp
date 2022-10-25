#include <iostream>

std::pair<int, double> foo();

int main()
{
	auto [i, d] = foo();

	auto fx = [=]() {return i + d; }; //C++17'de gecersiz C++20'de gecerli
	auto fy = [=]() {return i + d; }; //C++17'de gecersiz C++20'de gecerli
}
