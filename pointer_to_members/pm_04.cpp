#include <iostream>
#include <functional>

struct A {
	int mx{ 10 };
	//...
};

int main()
{
	using namespace std;

	int  A::* ptr = &A::mx;
	A a;

	std::cout << "a.mx = " << a.mx << "\n";

	invoke(ptr, a) = 40;
	std::cout << "a.mx = " << a.mx << "\n";
}
