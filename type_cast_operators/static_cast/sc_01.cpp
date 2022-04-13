#include <iostream>

int main()
{
	int x = 10;
	int y = 20;

	double d1 = x / y;
	double d2 = static_cast<double>(x) / y;

	std::cout << "d1 = " << d1 << '\n';
	std::cout << "d2 = " << d2 << '\n';
}
