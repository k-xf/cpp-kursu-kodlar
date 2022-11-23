#include <string>
#include <iostream>

#define exp     std::move(x)

int main()
{
	int x{ 10 };

	if constexpr (std::is_reference_v<decltype ((exp))>) {
		std::cout << "glvalue\n";
	}

	if constexpr (!std::is_lvalue_reference_v<decltype ((exp))>) {
		std::cout << "rvalue\n";

	}

	if constexpr (std::is_lvalue_reference_v<decltype ((exp))>) {
		std::cout << "lvalue\n";

	}

	if constexpr (!std::is_reference_v<decltype ((exp))>) {
		std::cout << "prvalue\n";

	}

	if constexpr (std::is_rvalue_reference_v<decltype ((exp))>) {
		std::cout << "xvalue\n";
	}
}
