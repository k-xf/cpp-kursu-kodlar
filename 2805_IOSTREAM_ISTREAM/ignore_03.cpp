//alıntı C++ faqs

#include <iostream>
#include <limits>

int main()
{
    int age = 0;

    while ((std::cout << "How old are you? ")
        && !(std::cin >> age)) {
        std::cout << "That's not a number; ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "You are " << age << " years old\n";
}
