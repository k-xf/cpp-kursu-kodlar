#include <vector>
#include <iostream>

template <typename InIter>
void print_range(InIter beg, InIter end, const char *p = " ")
{
	while (beg != end)
		std::cout << *beg++ << p;

	std::cout << '\n';
}

int main()
{
	std::vector ivec{ 2, 5, 8, 1, 9, 3, 6 };

	print_range(ivec.begin(), ivec.end());
	print_range(ivec.rbegin(), ivec.rend());
	print_range(rbegin(ivec), rend(ivec));
}
