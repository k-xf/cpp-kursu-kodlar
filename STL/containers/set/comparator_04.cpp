#include <iostream>
#include <set>


struct Comp {
	bool operator()(int a, int b)const
	{
		return std::abs(a) < std::abs(b);
	}
};

int main()
{
	using namespace std;

	set<int, Comp> s{ -12, 5, -5, 9, -7, 6, 2, -4 };

	for (auto i : s)
		cout << i << ' ';
}

