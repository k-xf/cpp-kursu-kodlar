#include <vector>
#include <ranges>
#include <iostream>

int main()
{
	using namespace std;

	vector ivec{1, 2, 3, 4, 5, 15, 25, 40, 60 }; //CTAD
	
	for (auto i : views::take(ivec, 4)) {
		cout << i << ' '; //first 4
	}
}
