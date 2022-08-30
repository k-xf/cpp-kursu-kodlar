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
	print(mylist);
	mylist.erase_after(mylist.begin());
	print(mylist);
	const auto iter_first = mylist.before_begin();
	const auto iter_last = next(iter_first, 3);
	mylist.erase_after(iter_first, iter_last);
	print(mylist);
}
