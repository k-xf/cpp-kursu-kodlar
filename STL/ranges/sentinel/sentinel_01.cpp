#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<auto EndVal>
struct EndValue
{
	constexpr bool operator==(auto pos)const
	{
		return *pos == EndVal;
	}
};

int main()
{
	using namespace std;

	vector ivec{12, 5, 218, 9, 3, 24, -1, 9, 41, 6};

	ranges::for_each(ivec.begin(), EndValue<-1>{}, 
		[](int x) { std::cout << x << ' '; });	// Output : 12 5 218 9 3 24
}
