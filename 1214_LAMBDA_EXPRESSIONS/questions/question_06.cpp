int main()
{
	int a[10]{};

	auto f = [a]()mutable {a = nullptr; };
	auto g = [a = a]()mutable {a = nullptr; };
	auto h = [a]() {++* a; };
	auto j = [a = a]() {++* a; };
}
