#include <functional>
#include <utility>

template <class... Args>
auto delay_invoke_foo(Args... args) {
    return[...args = std::move(args)]() -> decltype(auto) {
        return foo(args...);
    };
}
