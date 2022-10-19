#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::istringstream iss("Necati Ergin");
    std::string str;

    iss >> str;
    std::cout << str << '\n';
    iss.seekg(0, std::ios_base::beg); 
    iss >> str;
    std::cout << str << '\n';
    iss.seekg(1, std::ios_base::cur); 
    iss >> str;
    std::cout << str << '\n';
    iss.seekg(-6, std::ios_base::cur); 
    iss >> str;
    iss.seekg(-5, std::ios_base::end); 
    iss >> str;
    std::cout << str << '\n';
}
