#include <mutex>
#include <iostream>

class Nec {
public:
	void func()
	{
		std::lock_guard<std::recursive_mutex> guard{mtx};
		std::cout << "func cagrildi" << std::endl;
		foo();
		std::cout << "func sona eriyor" << std::endl;

	}

	void foo()
	{
		std::lock_guard<std::recursive_mutex> guard{mtx};
		std::cout << "foo cagrildi" << std::endl;
		std::cout << "foo sona eriyor" << std::endl;

	}

private:
	std::recursive_mutex mtx;
};

int main()
{
	Nec nec;

	try {
		nec.func(); //may throw exception
	}
	catch (const std::system_error &ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}
}

