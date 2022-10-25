#include <iostream>

class Myclass {
	
public:
	void f()
	{
		Myclass x;
		foo(x); //geçerli ADL
	}

	friend void foo(Myclass)
	{
		std::cout << "friend foo\n";
	}
};

int main()
{
	Myclass m;
	m.f();
}
