#include <type_traits>
#include <iostream>


#define   e(a)			decltype((a))

int main()
{
	int x = 10;

	if constexpr (std::is_lvalue_reference_v<e(x)>) {
		std::cout << "L value expression\n";
	}
	else if constexpr (std::is_lvalue_reference_v<e(x)>) {
		std::cout << "X value expression\n";	
	}
	else {
		std::cout << "PR value expression\n";	
	}
}
