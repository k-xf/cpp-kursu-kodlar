template<typename T>
struct ValCat {
	static constexpr const char* p = "PR value";
};

template <typename T>
struct ValCat <T&> {
	static constexpr const char* p = "L value";
};

template <typename T>
struct ValCat <T&&> {
	static constexpr const char* p = "X value";
};

#include <iostream>

#define  print_val_cat(expr)   std::cout << "value category of expr '" #expr "' is : " << ValCat<decltype((expr))>::p << '\n'

class Nec{};

Nec foo();
Nec& bar();
Nec&& baz();

int main()
{
	Nec x{};
	const Nec y{};

	print_val_cat(x);
	print_val_cat(y);
	print_val_cat(foo());
	print_val_cat(bar());
	print_val_cat(baz());
	print_val_cat(std::move(x));
	print_val_cat(std::move(y));

	print_val_cat("necati");
	print_val_cat(void());
	print_val_cat(nullptr);

	int ival{ 10 };
	int* ptr{ &ival };
	print_val_cat(ival + 5);
	print_val_cat(++ival);
	print_val_cat(ival++);
	print_val_cat(*ptr);
	print_val_cat(ptr[0]);
	print_val_cat(foo);
	print_val_cat(std::move(foo));
}
