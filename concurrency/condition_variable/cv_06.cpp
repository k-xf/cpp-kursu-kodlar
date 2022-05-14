#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cvar;
std::mutex cv_m; 
bool ready_flag{ false };

void consumer(int id)
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout<< "thread id" << id << " is waiting..." << std::endl;
    cvar.wait(lk, [] {return ready_flag; });
    std::cout<< "thread id" << id << " finished waiting..." << std::endl;
    //...
}

void producer()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1500ms);
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cout << "production complete and is notifying..." << std::endl;
    }
    cvar.notify_all();
    std::this_thread::sleep_for(1500ms);
    {
        std::lock_guard<std::mutex> lk(cv_m);
        ready_flag = true;
        std::cout << "notifying again..." << std::endl;
    }
    cvar.notify_all();
}

int main()
{
    std::thread ta[10];
    
    for (int i = 0; i < 10; ++i) {
        ta[i] = std::thread{ consumer, i + 1 };
    }
    std::thread tprod{ producer };

    for (auto& th : ta)
        th.join();

    tprod.join();
}
