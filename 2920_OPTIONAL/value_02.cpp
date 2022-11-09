#include <optional>
#include <string>
#include <iostream>

int main()
{
	std::optional<std::string> op{ "oguz karan" };

	std::cout << op.value() << "\n";
	op.value().assign(5, 'A');
	std::cout << op.value() << "\n";
	op = std::nullopt;

	try {
		std::cout << op.value() << "\n";
	}
	catch (const std::bad_optional_access& ex) {
		std::cout << "hata yakalandi : " << ex.what();
	}
}
