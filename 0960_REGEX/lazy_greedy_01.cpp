#include <string>
#include <iostream>
#include <regex>

using namespace std;

void print_matches(const std::string& str, const std::regex& rgx)
{
	sregex_iterator iter{ str.begin(), str.end(), rgx };
	sregex_iterator end;

	while (iter != end) {
		cout << "|" << iter->str() << "|\n";
		++iter;
	}
}

int main()
{
	string str = "<isim>Necati</isim>"
		"<isim>Omer Faruk</isim>"
		"<isim>Cansu</isim>"
		"<isim>Tufan</isim>"
		"<isim>Selin</isim>"
		"<isim>Hakan</isim>";
	regex rgx{ "<isim>(.*?)</isim>" };
	//regex rgx{ "<isim>(.*)</isim>" };

	print_matches(str, rgx);
}
