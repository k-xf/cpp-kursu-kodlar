consteval int sum_square(int x, int y)
{
	return x * x + y * y;
}


constexpr int SumSquare(int x, int y)
{
	return x * x + y * y;
}

int main()
{
	int a = 5;
	int b = 7;

	//constexpr auto x1 = SumSquare(a, b); //invalid, initializer is not a constant expression
	auto x2 = SumSquare(a, b); //valid
	constexpr auto x3 = SumSquare(10, 20); //valid
	constexpr auto x4 = sum_square(3, 5); //valid;
	//auto x5 = sum_square(a, b); //invalid, arguments are not constant expression
}




