#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


int main()
{
	using namespace std;

	ifstream ifs{ "primes.dat", ios::binary };
	if (ifs.fail()) {
		cerr << "dosya acilamadi\n";
		return 1;
	}

	//int ival;
	constexpr int size = 100;

	vector<int> ivec(100);

	while (ifs.read(reinterpret_cast<char*>(ivec.data()), sizeof(int) * ivec.size())) {
		cout << "okunan byte sayisi : " << ifs.gcount() << "\n";
		auto n = ifs.gcount() / sizeof(int);
		copy(ivec.begin(), ivec.begin() + n, ostream_iterator<int>(cout, " "));
	}
}
