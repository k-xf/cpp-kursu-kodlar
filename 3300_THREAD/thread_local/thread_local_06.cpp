#include <thread>
#include <iostream>
#include <syncstream>

void thread_func(const std::string& thread_name) 
{
    for (int i = 0; i < 3; ++i) 
    {
        thread_local int x = 0;
        x++;
        std::osyncstream{ std::cout } << "thread[" << thread_name << "]: x = " << x << std::endl;
    }
}

int main() 
{
    std::thread t1(thread_func, "t1");
    std::thread t2(thread_func, "t2");
    std::thread t3(thread_func, "t3");
    
    t1.join();
    t2.join();
    t3.join();
}
