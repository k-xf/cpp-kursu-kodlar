#include <iostream>
#include <set>

int main()
{
	using namespace std;

	const auto f = [](int a, int b) {return abs(a) < abs(b); };
	set<int, decltype(f)> s{ -12, 5, -5, 9, -7, 6, 2, -4 };

	for (auto i : s)
		cout << i << ' ';
}

