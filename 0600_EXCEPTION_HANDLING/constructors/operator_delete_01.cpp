#include <stdexcept>
#include <iostream>

void* operator new(std::size_t sz)
{
    std::cout << "operator new called for the size of : " << sz << "\n";

    if (sz == 0)
        ++sz;

    if (void* ptr = std::malloc(sz))
        return ptr;

    throw std::bad_alloc{};
}

void operator delete(void* ptr) noexcept
{
    std::cout << "operator delete called for the address of : " << ptr << "\n";
    std::free(ptr);
}


struct Nec {
public:
    Nec()
    {
        throw std::runtime_error{ "error in Nec ctor!\n" };
    }
    unsigned char buffer[1024]{};
};


int main()
{
    try {
        Nec* p = new Nec;
        delete p;
    }
    catch (const std::exception& ex) {
        std::cout << "exception caught: " << ex.what() << '\n';
    }

}
