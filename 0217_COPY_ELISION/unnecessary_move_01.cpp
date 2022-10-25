#include <iostream>

struct A {
	A() 
	{
		std::cout << "default ctor\n";
	}

	A(const A&)
	{
		std::cout << "copy ctor\n";
	}

	A(A &&)
	{
		std::cout << "move  ctor\n";
	}
};

A func() 
{ 
	A ax;

	return std::move(ax); //bunu yapmayın
}

A foo()
{
	return std::move(A{}); //bunu yapmayın
}

A create()
{
	A ax;

	//
	return ax;
}

int main()
{
	//A x{ foo() };
	//A y{ func() };
	//A z{ std::move(create())}; //bunu yapmayin
}
