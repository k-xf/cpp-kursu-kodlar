#include <iostream>

int main()
{
	int x = 10;
	x = ++x; //ub  before C++17

	std::cout << "x = " << x << "\n";

}
