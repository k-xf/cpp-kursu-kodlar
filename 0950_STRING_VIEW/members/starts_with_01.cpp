#include <iostream>
#include <string_view>

using namespace std;

int main()
{
	string_view str{ "life is very short" };

	std::cout << boolalpha << str.starts_with("life") << "\n";
	std::cout << boolalpha << str.starts_with("time") << "\n";
	std::cout << boolalpha << str.ends_with("short") << "\n";
	std::cout << boolalpha << str.ends_with("long") << "\n";
}
