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

	forward_list<string> mylist;

	mylist.push_front("ali");
	mylist.push_front("can");
	print(mylist);
	mylist.insert_after(next(mylist.begin()), "gul");
	print(mylist);
	mylist.insert_after(mylist.begin(), "eda");
	print(mylist);
	mylist.insert_after(mylist.before_begin(), { "tan", "naz", "efe" });
	print(mylist);

}
