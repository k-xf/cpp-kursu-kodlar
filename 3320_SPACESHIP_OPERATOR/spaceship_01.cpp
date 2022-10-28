#include <compare>
#include <iostream>

int main()
{
	using namespace std;

	cout << boolalpha;

	cout << (10 <=> 5 > 0) << '\n';		//true
	cout << (10 <=> 5 < 0) << '\n';		//false
	cout << (10 <=> 5 <= 0) << '\n';	//false
	cout << (10 <=> 5 >= 0) << '\n';	//true
	cout << (10 <=> 5 == 0) << '\n';	//false
	cout << (10 <=> 5 != 0) << '\n';	//true
}
