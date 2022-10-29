#include <iostream>

template <typename T>
struct Nec {
	Nec(T) {
		std::cout << "primary template\n";
	}
};

template <>
struct Nec<int> {
	Nec(const double& x)
	{
		std::cout << "specialization for Nec<int>\n";
	}
};

int main()
{
	Nec x{ 324 };
}
