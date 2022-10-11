#include <vector>
#include <string>
#include "nutility.h" //rname, print
#include <ranges>

int main()
{
	using namespace std;

	vector<string> svec;
	rfill(svec, 30, rname);

	print(svec);

	for (const auto& s : views::filter(svec, [](const auto& s) { return s.length() % 2 == 0; }))
		cout << s << '\n'; // Uzunluğu çift olanlar yazılacak
}
