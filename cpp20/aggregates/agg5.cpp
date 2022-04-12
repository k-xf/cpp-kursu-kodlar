struct Nec {
	int a, b, c;
};

int main()
{
	Nec n1{ 1,2,3 }; // Valid C++17/C++20
	Nec n2(1, 2, 3); // Invalid at C++17, Valid at C++20.

	//--------------------------------------------------------------------------------

	Nec n3{ 1, 2.2, 3 }; // invalid : Possible loss of data (narrowing conversion)

	Nec n4(1, 2.2, 3); // Warning : Possible loss of data (narrowing conversion)

	////--------------------------------------------------------------------------------

	Nec n5(.b = 6); // Invalid C++17/C++20

	Nec n6{ .b = 6 }; // Valid at C++20. Invalid at C++17

}
