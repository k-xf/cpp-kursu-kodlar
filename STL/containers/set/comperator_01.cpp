#include <iostream>
#include <set>
#include <functional>


template <typename T>
void print(const std::set<T>& s)
{
	for (const auto& elem : s)
		std::cout << elem << ' ';

	std::cout << std::endl;
}


int main()
{
	using namespace std;

	//set<int, less<int>> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	//set<int, less<>> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	//set<int> s{ 2, 5, 3, 6, 4, 9, 8, 7, 12 };
	set s{ 2, 5, 3, 6, 4, 9, 8, 7, 12, 1};
	
	print(s);
}

