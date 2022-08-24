#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "nutility.h"
#include <fstream>
#include <iomanip>

using Person = std::pair<int, std::string>;

int main()
{
	using namespace std;

	vector<Person> pvec;
	pvec.reserve(10'000);
	generate_n(back_inserter(pvec), 10'000, [] {
		return pair{ Irand{1, 1000}(), rname() }; });

	sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2) {return p1.first < p2.first; });
	//sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2) {return p1.second < p2.second; });
	stable_sort(pvec.begin(), pvec.end(), [](const Person& p1, const Person& p2) {return p1.second < p2.second; });

	ofstream ofs{ "out.txt" };
	if (!ofs) {
		cerr << "out.txt dosyasi olusturulamadi\n";
		exit(EXIT_FAILURE);
	}

	ofs << left;
	for (const auto& [id, name] : pvec) {
		ofs << setw(12) << id << " " << name << '\n';
	}
}
