#include <iostream>

void f1()
{
	throw 5;
}

void f2()
{
	try {
		f1();
	}
	catch (int &x) {
		x++;
		throw;
	}
}

int main()
{
	try {
		f2();
	}
	catch (const int &a) {
		std::cout << "hata main islevinde yakalandi" << '\n';
		std::cout << "a = " << a << '\n';
	}
}
