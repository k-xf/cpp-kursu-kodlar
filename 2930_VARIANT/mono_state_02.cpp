#include <variant>
#include <iostream>
#include <string>

int main()
{
	std::variant<std::monostate, std::string, int, double> vx;

	if (std::holds_alternative<std::monostate>(vx))
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";

	if (std::get_if<std::monostate>(&vx))
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";

	if (std::get_if<0>(&vx))
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";

	if (vx.index() == 0)
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";

	if (!vx.index())
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";
}
