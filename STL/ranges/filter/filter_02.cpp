#include <vector>
#include <string>
#include "nutility.h" //print
#include <ranges>

int main()
{
	using namespace std;

	vector<string> svec;
	rfill(svec, 30, rname);

	print(svec);

	char c;

	cout << "icinde hangi karkaterler olanlar : ";
	cin >> c;

	for (const auto& s : views::filter(svec, [c](const auto& s) { return s.find(c) != string::npos; }))
		cout << s << '\n'; // İçerisinde belirli bir karakter olanları yazdırdık
}
