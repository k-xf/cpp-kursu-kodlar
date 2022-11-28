#include <forward_list>
#include <string>
#include <iostream>

int main()
{
	using namespace std;

	forward_list<string> mylist{ "eda", "can", "gul", "efe", "tan", "naz" ,"ela" };

	string name;
	std::cout << "enter the name to remove: ";
	cin >> name;

	auto iter = mylist.cbefore_begin(); 

	while (next(iter) != mylist.end()) {
		if (*next(iter) == name) {
			mylist.erase_after(iter);
			break;
		}
		++iter;
	}

	for (const auto& s : mylist)
		cout << s << ' ';
}
