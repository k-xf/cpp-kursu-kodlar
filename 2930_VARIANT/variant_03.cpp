#include <variant>
#include <iostream>
#include <string>

int main()
{
	std::variant<int, std::string> var{ "necati" };
	std::cout << var.index() << "\n";
	var = 234;
	std::cout << var.index() << "\n";
	try {
		int i = std::get<0>(var);
		std::cout << "i = " << i << "\n";
		std::string str = std::get<1>(var);
		std::cout << "str = " << str << "\n";
	}
	catch (const std::bad_variant_access& e) {
		std::cerr << "hata yakalandi  " << e.what() << "\n";
	}

}
