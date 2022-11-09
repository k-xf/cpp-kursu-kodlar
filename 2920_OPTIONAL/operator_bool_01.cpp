#include <optional>
#include <iostream>
#include <string>

std::optional<std::string> getMiddleName(const std::string& rname)
{
	//return {};
	return "alican";

}

int main()
{
	std::string str;
	///code

	if (auto ostr = getMiddleName(str); ostr)
		std::cout << *ostr << '\n';
	else
		std::cout << "ostr bos durumda\n";
}
