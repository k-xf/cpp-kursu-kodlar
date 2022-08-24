#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
	using namespace std;
	
	vector<int> ivec{ 2, 6, 0, 4, 8, 4, 3, 7, 21 };

	auto iter = partition_point(ivec.begin(), ivec.end(), [](int a) {return a % 2 == 0; });
	std::cout << "index for partition point :" << iter - ivec.begin() << '\n';
}

