#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>


int main()
{
	using namespace std;
	vector<int> ivec(100);
	mt19937 eng{ random_device{}() };
	uniform_int_distribution dist {0, 20};
	generate(ivec.begin(), ivec.end(), [&eng, &dist] {return dist(eng); });

	map<int, int> cnt_map;

	for (auto i : ivec)
		++cnt_map[i];

	cout << left;
	for (auto [value, count] : cnt_map) {
		cout << setw(5) << value << count << "\n";
	}
}
