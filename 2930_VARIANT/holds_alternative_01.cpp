#include <variant>
#include <string>
#include <iostream>

int main()
{
	std::cout.setf(std::ios::boolalpha);
	std::variant<int, std::string> v = "abc";
	std::cout << "variant holds int     : " << std::holds_alternative<int>(v) << "\n";
	std::cout << "variant holds string  : " << std::holds_alternative<std::string>(v) << "\n";
	std::cout << "\n\n";

	v = 23;

	std::cout << "variant holds int     : " << std::holds_alternative<int>(v) << "\n";
	std::cout << "variant holds string  : " << std::holds_alternative<std::string>(v) << "\n";
	std::cout << "\n\n";
}
