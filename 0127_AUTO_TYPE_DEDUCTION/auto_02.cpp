
int main()
{
	int x = 10;
	const int c  = 20;
	int& rx = x;
	const int& rc = c;

	auto a1 = x; //int a1 = x;
	auto a2 = c; //int a2 = c;
	auto a3 = rx; //int a3 = rx;
	auto a4 = rc; //int a4 = rc;
}
