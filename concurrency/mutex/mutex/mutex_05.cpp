#include <mutex>
#include <iostream>
#include <exception>

std::mutex mtx;

int main()
{
	try {
		mtx.lock();
		mtx.lock();
    //...
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
		//exception caught: device or resource busy: device or resource busy
	}
}
