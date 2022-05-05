#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <syncstream>

class TSCounter {
public:
    TSCounter() = default;

    unsigned int get() const 
    {
        std::shared_lock lock(m_mtx);
        return m_val;
    }

    unsigned int increment() 
    {
        std::unique_lock lock(m_mtx);
        return ++m_val;
    }

    void reset() 
    {
        std::unique_lock lock(m_mtx);
        m_val = 0;
    }

private:
    mutable std::shared_mutex m_mtx;
    unsigned int m_val{ 0 };
};

int main() 
{
    TSCounter counter;

    auto f = [&counter]() {
        for (int i = 0; i < 3; i++) {
            std::osyncstream(std::cout) << std::this_thread::get_id() << ' ' << counter.increment() << '\n';
        }
    };

    std::thread th1(f);
    std::thread th2(f);
    std::thread th3(f);

    th1.join();
    th2.join();
    th3.join();
}

