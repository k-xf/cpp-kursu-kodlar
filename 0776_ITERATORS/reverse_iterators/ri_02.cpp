#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	vector<string> svec{ "metin", "ahmet", "nuri", "belgin", "samet","deniz" };

	if (auto iter = find_if(svec.begin(), svec.end(), [](const string& s) {return s.contains('a'); }); iter != svec.end()) {
		std::cout << "found... " << *iter << "\n";
	}
	else {
		std::cout << "not found\n";
	}


	if (auto riter = find_if(svec.rbegin(), svec.rend(), [](const string& s) {return s.contains('a'); }); riter != svec.rend()) {
		std::cout << "found... " << *riter << "\n";
	}
	else {
		std::cout << "not found\n";
	}

}
