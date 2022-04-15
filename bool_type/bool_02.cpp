#include <iostream>

int main()
{
	int x = 10;
	int y = 0;
	bool b = x;
	int* pn = nullptr;
	int* px = &x;

	std::cout << std::boolalpha;

	std::cout << "b = " << b << "\n";
	b = y;
	std::cout << "b = " << b << "\n";
	b = pn;
	std::cout << "b = " << b << "\n";
	b = px;
	std::cout << "b = " << b << "\n";
}
