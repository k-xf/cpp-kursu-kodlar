#include <array>

template <typename T>
using array5 = std::array<T, 5>;

template <size_t n>
using intarray = std::array<int, n>;

int main()
{
	array5<double> a1{1, 2, 3, 4, 5};
	intarray<3> a2{ 1, 2, 3 };
}
