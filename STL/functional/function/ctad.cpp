#include <functional>

int foo(int);
double func(double);
void bar();

int main()
{
	std::function f1 = foo;
	std::function f2 = func;
	std::function f3 = bar;
}
