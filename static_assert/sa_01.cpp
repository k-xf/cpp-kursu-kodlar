#include <type_traits>

template <typename T>
int f(T t) 
{
    static_assert(std::is_integral<T>(), "T must be integral");
    return 42;
}

int main() 
{
    f(1.2);
}

