#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <functional>

int main()
{
	using namespace std;
	
	vector<int> ivec;
	ivec.reserve(10'000);
	mt19937 eng;
	uniform_int_distribution dist{ 0, 100'000 };
	generate_n(back_inserter(ivec), 10'000, [&] {return dist(eng); });
	partial_sort(ivec.begin(), ivec.begin() + 20, ivec.end());
	//partial_sort(ivec.begin(), ivec.begin() + 20, ivec.end(), greater{});
	copy(ivec.begin(), ivec.begin() + 20, ostream_iterator<int>{cout, "\n"});
}

