#include <stdexcept>
#include <future>
#include <iostream>

int func()
{
	//throw std::runtime_error{ "error from func\n" };
	return 1;
}

int main()
{
	try {
		auto ftr = async(std::launch::async, func);
		auto val = ftr.get();
		std::cout << "return value is: " << val << "\n";
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << "\n";
	}
}
