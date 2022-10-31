#include <random>
#include <iostream>

using namespace std;

int main()
{
	mt19937 eng{ random_device{}() };
	uniform_int_distribution<>dist{ 1940, 2019 };

	for (int i = 0; i < 100; ++i)
		cout << dist(eng) << " ";
}
