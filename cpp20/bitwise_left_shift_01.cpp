#include <iostream>

int main()
{
	int x = -1;
	x <<= 1;		// C++17 UB. C++20 Valid 

	std::cout << "x = " << x << '\n';
}
