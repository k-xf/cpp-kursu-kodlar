#include <iostream>

class Nec {
	int mx, my;
	friend void func();

};

Nec foo()
{
	return Nec{};
}

void func()
{
	auto [x, y] = foo(); //Structured Binding
	std::cout << "mx = " << x << '\n' << "my = " << y << '\n';
}

int main()
{
	func();
}
