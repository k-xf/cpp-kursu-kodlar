#include <iostream>
#include <ranges>
#include <list>
#include <string>
#include "nutility.h"

int main()
{
	using namespace std;

	list<string> slist;
	rfill(slist, 10, rname); //nutility.h
	print(slist); //nutility.h

	for (auto x : views::reverse(slist) | views::take(5)) {
		cout << x << ' ';
	}
}
