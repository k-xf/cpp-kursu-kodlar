#include <memory>
#include "triple.h"
#include <iostream>


void func()
{
	//throw std::exception{};
}

int main()
{
	std::cout << ios::unitbuf;
	std::cout << "main started\n";

	try {
		std::unique_ptr<Triple>upx(new Triple{ 10, 20, 30 });

		std::cout << (upx ? "not empty" : "empty") << '\n';
		std::cout << *upx << '\n';
		upx->set(3, 6, 7);
		func();
		std::cout << *upx << '\n';
		std::cout << "end of the block\n";
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';

	}

	std::cout << "main goes on\n";
}
