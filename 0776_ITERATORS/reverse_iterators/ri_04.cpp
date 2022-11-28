// std::make_reverse_iterator C++14

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

	auto iter_beg = ivec.begin();
	auto iter_end = ivec.end();

	print_range(make_reverse_iterator(iter_end), make_reverse_iterator(iter_beg));

}
