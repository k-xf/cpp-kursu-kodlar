#include <iostream>

struct A {
	A()
	{
		std::cout << "default ctor this = " << this << "\n";
	}

	A(const A&) = delete;
	A(A &&) = delete;
};

void func(A)
{

}

A foo()
{
	return A{};
}

int main()
{
	A ax = A{};
	func(A{});
	A ay = foo();
}
