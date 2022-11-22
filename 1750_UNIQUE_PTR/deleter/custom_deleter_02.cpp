#include <iostream>
#include <memory>
#include <string>

int main()
{
	using namespace std;

	auto f = [](string* p) {
		cout << "lambda deleter deletes the string at the address " << p << '\n';
		delete p;
	};

	//unique_ptr<string, decltype(f)> uptr{ new string{"Necati"}, f };
	unique_ptr<string, decltype(f)> uptr{ new string{"Necati"} }; //C++20
}
