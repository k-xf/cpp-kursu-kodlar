#include <vector>
#include <iostream>
#include <new>

struct Nec {
	unsigned char buffer[1024 * 1024 * 16];
};

std::vector<Nec*> pvec{};

int main()
{
	std::cout << "sizeof(Nec) = " << sizeof(Nec) << '\n';
	int cnt{};

	for (;;) {
		auto p = new(std::nothrow)Nec;
		if (!p) {
			std::cout << "cannot allocate memory for Nec object!\n";
			break;
		}
		pvec.push_back(p);
		std::cout << ++cnt << '\n';
	}

	for (auto p : pvec)
		delete p;
}
