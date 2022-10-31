#include <iostream>
#include <chrono>

long long fib(unsigned n)
{
	return n < 2 ? n : fib(n - 1) + fib(n - 2);
}


int main()
{
	unsigned n;

	std::cout << "bir sayi girin: ";
	cin >> n;
	auto start = std::chrono::steady_clock::now();
	auto val = fib(n);
	auto end = std::chrono::steady_clock::now();
	cout << "fib(" << n << ") = " << val << "\n";
	cout << "sure : " << std::chrono::duration<double>{end - start}.count() << " saniye\n";
}
