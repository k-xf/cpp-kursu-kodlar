#include <iostream>

struct Nec {
	int i{ 7 };
	Nec() = delete;  //User declared defaulted
};


int main()
{
	Nec x; // Invalid at C++17 and C++20

	Nec y{}; // Valid at C++17. Invalid at C++20
}
