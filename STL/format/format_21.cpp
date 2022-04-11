#include <iostream>
#include <format>

int main()
{
	using namespace std;
	std::cout << std::format("Ali Aksoy C++ programcisidir") << "\n";

	//----------------------------------------------------------------------------------------------

	int x = 23;
	double d = 4.5;
	std::cout << std::format("{} {} {}", x, d, "ali") << "\n"; // 23 4.5 ali

	//----------------------------------------------------------------------------------------------

	string name1{ "Necati" };
	int cnt1{ 20 };

	std::cout << std::format("{} isimli kisinin {} kitabi var", name1, cnt1) << "\n";  // Necati kisisinin 20 kitabi var

	//----------------------------------------------------------------------------------------------

	std::cout << format("{} {}\n", "merhaba", "dunya"); // merhaba dunya

	//----------------------------------------------------------------------------------------------

	string name2{ "Necati" };
	int cnt2{ 20 };
	std::cout << std::format("{1} isimli kisinin {0} kitabi var", cnt2, name2) << "\n"; // Necati kisisinin 20 kitabi var
	std::cout << std::format("{} isimli kisinin {} kitabi var", cnt2, name2) << "\n"; // 20 kisisinin Necati kitabi var

	//----------------------------------------------------------------------------------------------

	int y = 47802;
	std::cout << format("{0} {0} {0}\n", y); // 47802 47802 47802

	//----------------------------------------------------------------------------------------------

	int z = 47802;
	std::cout << format("{0:b} {0:X} {0:#X} {0:d} {0:o}", z);
	// 1011101010111010 BABA 47802 135272
}
