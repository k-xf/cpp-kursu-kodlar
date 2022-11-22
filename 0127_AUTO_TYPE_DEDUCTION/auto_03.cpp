int main()
{
	int a[] = { 1, 2, 3 };
	const int ca[] = { 3, 4, 6, 8 };

	auto x = a;  //int *x = a;
	auto y = ca;  //const int *y = ca;
	auto z = "neco";  //const char* z = "neco";
}
