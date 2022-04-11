#include <iostream>
#include <format>

int main()
{
	using namespace std;

	int x{};
	//cout << format("{}", &x) << "\n"; // geçersiz.
	//cout << format("{:p}", &x) << "\n"; // geçersiz

	cout << format("{}", (void*)&x) << "\n"; 
	cout << format("{:p}", (void*)&x) << "\n"; 
	cout << format("{:p}", static_cast<void*>(&x)) << "\n";  // 

	cout << format("{}", nullptr) << "\n"; // 0x0
	cout << format("{:p}", nullptr) << "\n"; // 0x0
}
