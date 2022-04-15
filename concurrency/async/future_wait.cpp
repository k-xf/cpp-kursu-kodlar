// örnek kod cpprefence.com sitesinden alınıp degistirilmistir:

#include <chrono>
#include <iostream>
#include <future>
#include <thread>

int fib(int n)
{
    return (n < 3) ? 1 : fib(n - 1) + fib(n - 2);
}

int main()
{
    auto ftr1 = async(std::launch::async, []() { return fib(40);});
    auto ftr2 = async(std::launch::async, []() {return fib(43);});

    std::cout << "waiting... " << std::flush;
    const auto start = std::chrono::system_clock::now();

    ftr1.wait();
    ftr2.wait();

    const auto diff = std::chrono::system_clock::now() - start;
    std::cout << std::chrono::duration<double>(diff).count() << " seconds\n";

    std::cout << "ftr1: " << ftr1.get() << '\n';
    std::cout << "ftr2: " << ftr2.get() << '\n';
}
