#include <iostream>

struct A {
	A() = delete;
};

struct B {
	int x{ 1 };
	B(int) = delete;
};

struct C
{
	int x;
	C();
};

C::C() = default;

int main()
{
	A a; // Invalid at C++17 and C++20
	
	B b{ 12 }; // Valid at C++17. Invalid at C++20
}
