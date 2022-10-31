#include <chrono>
#include <iostream>

int main()
{
	//default ctor epoche time_point değerinde bir nesne oluşturuyor

	std::chrono::system_clock::time_point x;

	auto val = std::chrono::system_clock::to_time_t(x);

	std::cout << "val = " << val << "\n";
}
