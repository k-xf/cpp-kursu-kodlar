template<typename T>
class Tclass {
};

struct A {
};

template<typename T>
concept nec = requires {
    typename Tclass<T>;
};

int main()
{
    static_assert(nec<int>); // valid
    static_assert(nec<A>); // valid
}
