#include <forward_list>
#include <string>
#include <iostream>

template <typename T>
void print(const std::forward_list<T> &flist)
{
	for (const auto& elem : flist)
		std::cout << elem << ' ';
	std::cout << '\n';
}

int main()
{
	using namespace std;

	forward_list<string> mylist{ "eda", "can", "gul", "efe", "tan", "naz" ,"ela" };

	while (!mylist.empty()) {
		print(mylist);
		mylist.pop_front();
	}
}
