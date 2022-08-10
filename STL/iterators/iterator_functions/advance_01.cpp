#include <list>
#include <iostream>
#include <iterator>

int main()
{
	using namespace std;

	list<string> slist{ "metin", "ahmet", "nuri", "belgin", "samet", "zeki", "deniz", "nur"};

	auto iter = slist.begin();
	cout << *iter << '\n';
	advance(iter, 4);
	cout << *iter << '\n';
	advance(iter, -2);
	cout << *iter << '\n';
}
