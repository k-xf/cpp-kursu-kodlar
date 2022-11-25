#include <type_traits>

template<typename T>
void func(T)
{
	static_assert(std::is_pointer_v<T>, "template argumani pointer turu degil");
}

int main()
{
	int x{};
	int* p{ &x };

	//func(x);
	func(p);
}
