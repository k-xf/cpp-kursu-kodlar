#include <iostream>
#include <chrono>
#include <vector>
#include "nutility.h"
#include <random>
#include <algorithm>

using namespace std;
using namespace chrono;

int main()
{
	vector<int> ivec;
	mt19937 eng;
	uniform_int_distribution<> dist{ 0, 1000000 };
	cout << "islem basliyor\n";
	auto tp_start = steady_clock::now();

	fc(ivec, 10'000'000, [&] {return dist(eng); });
	sort(ivec.begin(), ivec.end());

	auto tp_end = steady_clock::now();
	cout << "islem sona erdi\n";

	cout << "sure : " << duration_cast<milliseconds>(tp_end - tp_start).count() << " milisaniye \n";
	cout << "sure : " << duration<double>(tp_end - tp_start).count() << " saniye \n";
}
