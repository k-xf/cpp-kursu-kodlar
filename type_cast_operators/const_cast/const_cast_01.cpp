#include <iostream>

int main()
{
	int x{ 3 };
	const int* ptc{ &x };
	//code
	int* p = const_cast<int*>(ptc);
	*p = 99;

	std::cout << "x = " << x << "\n";
}
