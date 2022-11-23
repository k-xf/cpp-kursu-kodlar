#include <string>

std::string  func();
std::string& foo();

std::string  f1() { return func(); }
std::string  &f2() { return foo(); }

decltype(auto) f3() { return func(); }
decltype(auto) f4() { return foo(); }


decltype(auto) f5()
{
	int x = 10;

	return (x); //ub
}
