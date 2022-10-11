#include <iostream>
#include <string>
#include <ranges>

std::string trim(std::string s)
{
	namespace vw = std::ranges::views;
	auto v = s | vw::drop_while(std::isspace)
		| vw::reverse
		| vw::drop_while(std::isspace)
		| vw::reverse;

	return { v.begin(), v.end() };
}

int main()
{
	std::string str{ "	 \t\nmustafa aksoy\t		\n" };
	std::cout << "|" << trim(str) << "|";
}
