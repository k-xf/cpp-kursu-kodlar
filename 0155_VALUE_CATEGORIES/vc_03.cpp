#include <iostream>

class Nec {
	//
};


void foo(Nec&)
{
	std::cout << "foo(Nec&)\n";
}

void foo(const Nec&)
{
	std::cout << "foo(const Nec&)\n";
}

void foo(Nec&&)
{
	std::cout << "foo(Nec&&)\n";
}

Nec g;
Nec bar() { return g; }
Nec& baz() { return g; }

int main()
{
	Nec x;
	const Nec cx;

	foo(x);
	foo(cx);
	foo(std::move(x));
	foo(Nec{});
	foo(bar());
	foo(baz());
}
