#include <iostream>
#include <string>
#include <variant>

int main()
{
	std::variant<std::string, int> v1;

	v1.emplace<0>("necati"); // OK
	std::cout << std::get<0>(v1) << '\n';
	v1.emplace<std::string>("velican"); // OK
	std::cout << std::get<0>(v1) << '\n';

	std::variant<std::string, std::string> v2;
	v2.emplace<1>("ghi"); // OK
	std::cout << std::get<1>(v2) << '\n';
	//v2.emplace<std::string>("abc"); //gecersiz
}
