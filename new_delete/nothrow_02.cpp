#include <new>
#include <iostream>

int main()
{
	//...
	void* vp = operator new(1024, std::nothrow);
	if (!vp) {
		std::cerr << "can not allocate memory!\n";
		return 1;
	}
	//...
}
