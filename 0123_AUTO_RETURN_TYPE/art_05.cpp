auto f(int n)
{
	if (n > 1) {
		return n * f(n - 1); // gecersiz
	}
	else {
		return 1;
	}
}
