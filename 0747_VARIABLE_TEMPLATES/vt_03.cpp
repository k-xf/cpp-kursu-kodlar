template<size_t base, size_t exp>
constexpr size_t power = base * power<base, exp - 1>;

template<size_t base>
constexpr size_t power<base, 0> = 1;

template<size_t base>
constexpr size_t power<base, 1> = base;


#include <iostream>

int main()
{
	std::cout << power<2, 0>;
}
