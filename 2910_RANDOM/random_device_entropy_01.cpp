#include <random>
#include <iostream>

int main()
{
	std::random_device device;
	std::cout << "entropy : " << device.entropy() << "\n";
}
