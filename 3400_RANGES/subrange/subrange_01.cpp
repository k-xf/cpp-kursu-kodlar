#include <vector>
#include <ranges>
#include <iostream>

int main()
{
	using namespace std;

	vector ivec{ 1, 2, 3, 4, 5 };

	ranges::subrange sr1{ ivec }; // CTAD

	cout << "sizeof(sr1) = " << sizeof(sr1) << '\n';

	auto &r1 = sr1.front(); //valid
	auto &r2 = sr1.back(); //valid

	ranges::subrange sr2{ ivec.begin(), ivec.end() };

	for (const auto i : sr2)
		cout << i << ' '; //1,2,3,4,5 
}
