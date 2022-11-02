#include <iostream>
#include <chrono>

int main()
{
	//default ctor epoche time_point değerinde bir nesne oluşturuyor

	std::chrono::system_clock::time_point x;

	std::cout << std::chrono::system_clock::to_time_t(x);
}
