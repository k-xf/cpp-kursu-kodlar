int main()
{
	auto &&r1 = 10;
	//int &&r1

	//type for auto is int
	// declaration type of r1 is int &&
	int x = 23;
	auto&& r2 = x;

	// type for auto is int&
	// int& && reference collapsing to int & type
	// declaration type of r2 is int &
}
