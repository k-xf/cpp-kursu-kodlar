#include <optional>
#include <iostream>

int main()
{
	std::optional<int> opt = {};

	try {
		int ival = opt.value();
		std::cout << "ival = " << ival << "\n";
	}
	catch (const std::bad_optional_access& e)
	{
		std::cout << "hata yakalandi : " << e.what() << '\n';
	}
}
