#include <initializer_list>

template <typename T>
void foo(T x);

template <typename T>
void bar(std::initializer_list<T>);

auto func() 
{
	foo({ 1, 3, 5, 7 }); //gecersiz
	bar({ 1, 3, 5, 7 }); //gecerli
}
