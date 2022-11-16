#include <variant>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	variant<int, string> vx{ "necati ergin" };
	cout << "vx.index() = " << vx.index() << "\n";
	cout << get<1>(vx).size() << "\n";
	auto vy = std::move(vx);
	cout << "vx.index() = " << vx.index() << "\n";
	cout << get<1>(vx).size() << "\n";
}
