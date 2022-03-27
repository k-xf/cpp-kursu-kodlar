//reference_wrapper'in constexpr bağlamda kullanılması 

#include <functional>

constexpr int foo(int x)
{
	return 2 * x - 3;
}

constexpr int bar(int x)
{
	return 3 * x + 7;
}

constexpr int baz(bool b)
{
	std::reference_wrapper r = foo; //C++20
	if (b)
		r = bar;

	return r(10);
}

int main()
{
	constexpr auto x = baz(true);
	constexpr auto y = baz(false);
}



