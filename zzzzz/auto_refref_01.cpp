#include <iostream>
#include <string>

void func(const std::string&)
{
	std::cout << "func(const std::string&)\n";
}

void func(std::string&)
{
	std::cout << "func(std::string&)\n";
}

void func(std::string&&)
{
	std::cout << "func(std::string&&)\n";
}

const std::string& const_lref_rt(const std::string& str)
{
	return str;
}

std::string& lref_rt(std::string& str)
{
	return str;
}

std::string&& rref_rt(std::string&& str)
{
	return std::move(str);
}

std::string value_rt(const std::string& str)
{
	return str;
}

int main()
{
	func(const_lref_rt("const lvalue reference")); // func(const std::string&)
	std::string str{ "ergin" };
	func(lref_rt(str)); // func(std::string&)
	func(rref_rt("rvalue reference")); // func(std::string&&)
	func(rref_rt(std::move(str))); // func(std::string&&)
	func(value_rt("tmp")); //func(std::string&&)
}
