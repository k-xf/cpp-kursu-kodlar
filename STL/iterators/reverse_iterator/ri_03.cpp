#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	vector<string> svec{ "metin", "ahmet", "nuri", "belgin", "samet","deniz" };

	if (auto riter = find_if(svec.rbegin(), svec.rend(), [](const string& s) {return s.contains('a'); }); riter != svec.rend()) {
		std::cout << "found... " << *riter << "\n";
		auto iter = riter.base();
		std::cout << *iter << "\n";
	}
	else {
		std::cout << "not found\n";
	}

}
