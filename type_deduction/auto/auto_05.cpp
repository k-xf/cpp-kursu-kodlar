#include <initializer_list>

int main()
{
	auto x = { 1 }; //copy initialization x is initializer_list<int>
	auto y = { 1, 5, 2 }; //copy initialization y is initializer_list<int>
	auto z{ 12 }; //z is int (not initializer_list<int> as before)
	auto t{ 12, 56 }; //invalid code (not initializer_list<int> as before)

	return 0;
}
