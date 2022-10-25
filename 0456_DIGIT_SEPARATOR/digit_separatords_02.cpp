//C++14 standartları ile dile eklenen tamsayi sabiti basamak ayiraci

#include <iostream>
#include <chrono>

int main()
{
	long long decn = 1'000'000'000LL;
	long long hexn = 0xFFFF'FFFFll;
	long long octn = 00'23'00LL;
	long long binn = 0b1010'0011LL;

	int x = 1048576;
	int y = 1'048'576;
	int z = 0X100000;
	int t = 0x10'0000;
	int m = 0'004'000'000;

	std::cout << std::boolalpha << (x == y && x == z && x == t && x == m) << '\n';
	double d1 = 1.602'176'565e-19;
	double d2 = 1.602176565e-19;

	long long a1 = 123456789ll;
	long long a2 = 123'456'789ll;
	long long a3 = 12'34'56'78'9ll;
	long long a4 = 12345'6789ll;

	using namespace std::chrono_literals;

	std::chrono::seconds timer = 1'674'456s + 5'300h;
}
