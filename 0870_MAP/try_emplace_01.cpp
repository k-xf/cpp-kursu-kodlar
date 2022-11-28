#include <map>
#include <iostream>

using namespace std;

struct Data {
	Data(int x, int y, int z) {
		std::cout << "Data(int, int, int)\n";
	};
};

int main()
{
	map<int, Data> x;
	x.emplace(make_pair(1, Data{ 2, 3, 4 } ));
	x.try_emplace(1, 2, 3, 4 );
}
