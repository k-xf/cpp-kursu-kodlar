#include <list>
#include <string>
#include <iterator>
#include <iostream>

int main()
{
    std::list<std::string> names{ "ali", "hasan", "ayse", "nur", "canan" };

    auto print = [&]() {
        for (const auto& s : names)
            std::cout << s << ' ';
        std::cout << '\n';
    };

    print();

    iter_swap(names.begin(), prev(names.end()));
    print();
    std::cout << "distance = " << distance(names.begin(), names.end()) << '\n';
    auto iter = names.begin();
    std::cout << *iter << '\n';
    advance(iter, 3);
    std::cout << *iter << '\n';
    iter_swap(iter, names.begin());
    print();
}
