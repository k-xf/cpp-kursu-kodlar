#include <any>
#include <iostream>

int main()
{
	using namespace std;

	any a{ 12 };

	try {
		int ival = any_cast<int>(a);
		cout << "ival = " << ival << '\n';
		a = 3.4;
		ival = any_cast<int>(a);
		cout << "ival = " << ival << '\n';
	}
	catch (const std::bad_any_cast& ex) {
		cout << "hata yakalandi: " << ex.what() << '\n';
	}
}
