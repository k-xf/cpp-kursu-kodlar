#include <iostream>

int main()
{
	unsigned int x = 1'654'913'129u;
	unsigned char* p = reinterpret_cast<unsigned char*>(&x);

	for (size_t i{}; i < sizeof x; ++i) {
		std::cout << static_cast<unsigned>(p[i]) << '\n';
	}
}
