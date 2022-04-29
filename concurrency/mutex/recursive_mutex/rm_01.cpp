#include <mutex>
#include <iostream>

class Nec {
public:
	void func()
	{
		std::lock_guard<std::mutex> guard{mtx};
		foo();
	}

	void foo()
	{
		std::lock_guard<std::mutex> guard{mtx};
	}

private:
	std::mutex mtx;
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

/*
	The C++ standard library permits the second attempt to throw a std::system_error 
	with the error code resource_deadlock_would_occur 
	if the platform detects such a deadlock.
	But this is not required and is often not the case.
*/
