#include <list>
#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::list<std::string> slist{ "mustafa yalcinkaya", "hasan karaman", "aysenur kursun", "nurdan denizcan", 
        "selami yozgatli" };

    auto print = [](const std::string &snote, const auto& con) {
        std::cout << snote << '\n';
        for (const auto& s : con)
            std::cout << std::quoted(s) << '\n';
        std::cout << '\n';
    };

    
    print("elements in slist: ", slist);
    std::vector<std::string> svec{ make_move_iterator(slist.begin()), make_move_iterator(slist.end()) };
    print("elements in slist after move:\n", slist);
    print("elements in svec:\n", svec);
}
