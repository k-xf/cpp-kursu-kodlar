#include <string>
#include <random>
#include <iostream>
#include <algorithm>


int main()
{
	using namespace std;

	string s{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	mt19937 eng{ random_device{}() };

	while (true) {
		cout << s << "\n";
		shuffle(begin(s), end(s), eng);
		(void)getchar();
		std::system("cls");
	}
}
