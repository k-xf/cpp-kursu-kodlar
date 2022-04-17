#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>

int main()
{
    std::vector<std::string> days{
        "17 Nisan 2022 Pazar",
        "18 Nisan 2022 Pazartesi",
        "19 Nisan 2022 Sali",
        "20 Nisan 2022 Carsamba",
        "23 Nisan 2022 Persembe",
        "24 Nisan 2022 Cuma",
        "25 Nisan 2022 Cumartesi" };


    for (const auto& d : days)
        std::cout << std::quoted(d) << '\n';

    std::list<std::string> dlist{ days.size() };

    reverse_copy(make_move_iterator(days.begin()), make_move_iterator(days.end()), dlist.begin()); //ADL
    std::cout << "after reverse copy\n\n";

    //strings in the vector are in moved-from state now
    for (const auto& d : days)
        std::cout << std::quoted(d) << '\n';

    std::cout << "\n\n";

    for (const auto& d : dlist)
        std::cout << d << '\n';

}
