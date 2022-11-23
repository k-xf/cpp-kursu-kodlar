#include <iostream>

int main()
{
	bool b{};
	int x = b;
	std::cout << "x = " << x << "\n";
	b = true;
	std::cout << "x = " << x << "\n";
	//int* p = b; //invalid;
}
