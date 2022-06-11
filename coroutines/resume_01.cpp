#include <coroutine>
#include <iostream>

struct ReturnObject {
    struct promise_type {
        ReturnObject get_return_object() 
        {
            return ReturnObject{ std::coroutine_handle<promise_type>::from_promise(*this) }; 
        }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void unhandled_exception() noexcept {}
        void return_void()noexcept {}

        auto get_handle() 
        {
            return std::coroutine_handle<promise_type>::from_promise(*this);
        }
    };

    std::coroutine_handle<promise_type> m_handle; 

    ReturnObject(std::coroutine_handle<promise_type> handle) :m_handle{ handle } { }
    operator std::coroutine_handle<>() const { return m_handle; }
};


int cnt{};

ReturnObject cfunc() 
{
    std::cout << ++cnt << ". hello from coroutine\n";
    co_await std::suspend_always{}; 
    std::cout << ++cnt << ". hello from coroutine\n";
    co_await std::suspend_always{}; 
    std::cout << ++cnt << ". hello from coroutine\n";
}


int main() 
{
    std::coroutine_handle<> handle = cfunc();
    std::cout << ++cnt << ". resuming coroutine from main\n";
    handle();
    std::cout << ++cnt << ". resuming coroutine from main\n";
    handle.resume(); 
}
