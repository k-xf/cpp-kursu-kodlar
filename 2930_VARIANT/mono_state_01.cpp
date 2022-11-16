// std::monostate

#include <variant>
#include <iostream>

class Data {
public:
	Data(int x) : mx{ x } {}
private:
	int mx;
};

int main()
{
	//std::variant<Data, int, double> v1;  //gecersiz Data sınıfının default ctor'ı yok
	std::variant<std::monostate, Data, int, double> v2; //gecerli

	std::cout << "index = " << v2.index() << "\n";  //0

	if (std::holds_alternative<std::monostate>(v2))
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";

	if (std::get_if<std::monostate>(&v2))
		std::cout << "variant bos (monostate)\n";
	else
		std::cout << "variant bos degil\n";

	v2 = Data{ 13 };
	std::cout << "index = " << v2.index() << "\n";
	v2 = 23;
	std::cout << "index = " << v2.index() << "\n";
	v2 = 4.5;
	std::cout << "index = " << v2.index() << "\n";
	v2 = std::monostate{};
	std::cout << "index = " << v2.index() << "\n";
	v2 = {};
	std::cout << "index = " << v2.index() << "\n";
}
