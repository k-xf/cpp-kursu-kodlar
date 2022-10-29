#include <vector>
#include <algorithm>
#include <functional>


template <typename T, typename P = std::less<T>>
auto insert_sorted(std::vector<T> &vec, T &&val, P pred = P{})
{
	return vec.insert(std::lower_bound(vec.begin(), vec.end(), std::forward<T>(val), pred), val);
}

#include "nutility.h"

int main()
{
	using namespace std;
	vector<int> ivec;

	Irand myrand{ 0, 1000 };

	fill_con(ivec, 20, myrand);
	sort(ivec.begin(), ivec.end(), greater<int>{});

	for (int i = 0; i < 40; ++i) {
		insert_sorted(ivec, myrand(), greater<int>{});
	}
	print_con(ivec);

	vector<string> svec;
	fill_con(svec, 10, random_name);


}
