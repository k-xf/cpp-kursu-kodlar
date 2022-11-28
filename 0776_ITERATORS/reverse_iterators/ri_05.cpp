#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	vector<string> svec{ "metin", "ahmet", "nuri", "belgin", "samet", "zeki", "deniz", "nur"};

	sort(svec.rbegin(), svec.rend());
	for (const auto& s : svec) {
		std::cout << s << " ";
	}

}
