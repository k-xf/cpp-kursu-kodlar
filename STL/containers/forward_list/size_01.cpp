#include <forward_list>
#include <string>
#include <iostream>


int main()
{
	using namespace std;

	forward_list<string> mylist{ "eda", "can", "gul", "efe", "tan", "naz" ,"ela" };
	cout << "size = " << distance(mylist.begin(), mylist.end());
}
