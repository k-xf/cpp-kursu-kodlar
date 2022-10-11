#include <list>
#include <string>
#include "nutility.h"
#include <iostream>
#include <ranges>
#include <iomanip>

int main()
{
	using namespace std;

	list<string> slist;

	rfill(slist, 20, rname); //listeye 20 tane rastgele isim ekleniyor nutility.h
	print(slist); //nutility.h
	size_t len;
	cout << "uzunluk değeri girin: ";
	cin >> len;

	auto v = views::drop_while(slist, 
		[len](const string& s) {return s.size() > len; });
	ranges::for_each(v, 
		[](const auto& s) {cout << quoted(s) << " "; });
}
