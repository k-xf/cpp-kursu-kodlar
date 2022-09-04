#include <iostream>

int main()
{
	for (int i = 0; i < 10; ++i) {
		static auto x = 5;
		std::cout << x << " ";
		x++;
	}
}
