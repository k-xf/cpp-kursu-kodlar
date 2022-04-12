struct Nec
{
	int x;
	bool flag;
};

int main()
{
	void* vptr{};
	Nec nec{ 12,vptr }; //Valid in C++17. Warning in C++20. void * to bool conversion is narrowing conversion.
	
	int x = 10;
	bool b{ &x }; // Syntax Error in C++20. Narrowing conversion
}
