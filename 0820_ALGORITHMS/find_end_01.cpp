#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
    std::vector<std::string> svec{"ali", "nur", "ece", "can", "ece", "ali", "nur", "ece", "tan"};
    std::vector<int>::iterator result;

    const auto list = { "ali", "nur", "ece" };

    if (auto iter = std::find_end(svec.begin(), svec.end(), list.begin(), list.end()); iter != svec.end()) {
        std::cout << "found at index : " << distance(svec.begin(), iter) << "\n";
    }
    else {
        std::cout << "not found\n";
    }
}
