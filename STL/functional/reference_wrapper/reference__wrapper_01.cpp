/*
	reference_wrapper is a rebindable reference
*/

#include <functional>
#include <iostream>

int main()
{
	int x = 15, y = 45;

	reference_wrapper<int> r = x;

	r = y;  //x'e y atanmıyor r y'ye bağlanıyor.

	std::cout << "x = " << x << "\n";
	r.get() = x;
	std::cout << "y = " << y << "\n";
}
