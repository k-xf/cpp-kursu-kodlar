#include <string>
#include <optional>
#include <iostream>

std::optional<std::string> getMiddleName(const std::string& rname);

int main()
{
	std::string name;
	//...
	auto op = getMiddleName(name);

	if (op.has_value()) {
		std::cout << "ikinci isim: " << *op << "\n";
		//
	}
	else {
		std::cout << "ikinci isim yok..." << "\n";
	}
}
