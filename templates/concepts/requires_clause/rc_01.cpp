
template<typename C>
concept nec = requires {
    typename C::value_type;
};

struct A
{
    using value_type = int;
};

template <typename T>
    requires nec<T>
class Myclass {

};

int main()
{
    //Myclass<int> x; // Syntax Error

    Myclass<A> x; // Valid
}
