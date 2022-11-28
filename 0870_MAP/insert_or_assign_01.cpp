#include <iostream>
#include <map>
#include <string>

int main()
{
	using namespace std;

	auto print_pair = [](const auto& p) {
		cout << "[" << p.first << ", " << p.second << "]\n";
	};

	auto print_result = [&](const auto& ip) {
		cout << (ip.second ? "inserted: " : "assigned : ");
		print_pair(*ip.first);
	};

	map<int, string> m;
	auto p = m.insert_or_assign(12, "necati");
	print_result(p);
	p = m.insert_or_assign(12, "salih");
	print_result(p);
}
