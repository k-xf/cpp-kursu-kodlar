#include <iostream>
#include <set>
#include <functional>


template <typename T, typename C>
void print(const std::set<T, C>& s)
{
	for (const auto& elem : s)
		std::cout << elem << ' ';

	std::cout << std::endl;
}

template <typename T>
using gset = std::set<T, std::greater<T>>;

int main()
{
	using namespace std;

	//set<int, greater<int>> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	//set<int, greater<>> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	gset<int> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	
	print(s);
}

