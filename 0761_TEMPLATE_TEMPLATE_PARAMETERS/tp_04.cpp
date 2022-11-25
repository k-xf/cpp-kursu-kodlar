#include <iostream>
#include <tuple>

template <typename T>
class A {

};

template <typename T>
class B {

};

template <typename T>
class C {

};

template <typename T, template <typename> typename ...Ts>
class Myclass {
public:
	Myclass()
	{
		std::cout << typeid(Myclass).name() << '\n';
		std::cout << typeid(std::tuple<Ts<T>...>).name() << '\n';
	}
};

int main()
{
	Myclass<double, A, B, C> x;
}
