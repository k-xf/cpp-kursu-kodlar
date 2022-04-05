#include <iostream>
#include <string>
#include <thread>
#include <mutex>

thread_local int tval{ 0 };
std::mutex cout_mutex;

void func(const std::string& thread_name)
{
    ++tval; //senkronizasyon gerekmiyor
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "tval in thread " << thread_name << " is " << tval << "\n";
}

int main()
{
    std::thread tx(func, "a");
    std::thread ty(func, "b");

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "tval in main: " << tval << '\n';
    }

    tx.join();
    ty.join();
}
