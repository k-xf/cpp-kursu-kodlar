#include <utility>
#include <string>

int main()
{
	using namespace std;

	pair x{ 1, 4.5 };  //pair<int, double>
	pair y("ayse"s, "fatma"); // pair<string, const char *>
	pair z = { 7u, 4.5f };  //pair<unsigned, float>
}
