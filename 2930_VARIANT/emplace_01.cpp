#include <variant>
#include <string>
#include <iostream>

int main()
{
	std::cout << std::boolalpha;

	auto f = [](const auto& val) {
		std::cout << "deger: " << val << '\n';
	};

	std::variant<bool, std::string> var;
	var = "necati";

	// bool ogeye atama yapildi
	std::cout << "index: " << var.index() << '\n';
	std::visit(f, var);

	var.emplace<1>("ekrem");
	std::cout << "index: " << var.index() << '\n';
	std::visit(f, var);

	var.emplace<std::string>("elif");
	std::visit(f, var);

	using namespace std::literals;
	var = "sinan"s;
	std::visit(f, var);

}
