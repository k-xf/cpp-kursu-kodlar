#include <iostream>

class Nec
{
public:
    Nec& foo(int i)
    {
        std::cout << "Nec::foo(int i) i = " << i << '\n';
        return *this;
    }
    Nec& bar(double d)
    {
        std::cout << "Nec::bar(double d) d = " << d << '\n';
        return *this;
    }
};

int ifunc()
{
    std::cout << "int ifunc()\n";
    return 1;
}

double dfunc()
{
    std::cout << "double dfunc()\n";
    return 1.4;
}

int main()
{
    Nec mynec;
    mynec.foo(ifunc()).bar(dfunc());
}
