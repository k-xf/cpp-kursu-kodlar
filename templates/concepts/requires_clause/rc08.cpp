#include <iostream>

template <typename T>
concept nec = requires(T x)
{
    std::cout << x;
    std::cout >> x;
};

struct A {};

int main()
{
    static_assert(nec<A>); //invalid
}
