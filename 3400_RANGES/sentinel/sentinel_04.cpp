

#include <string>
#include <algorithm>

struct UnreachableSentinel {
	constexpr bool operator==(const auto& val) const
	{
		return false;
	}
};

constexpr UnreachableSentinel UnReachableSentinel_t;


/*
	find algoritması içinde
	while (*beg != UnReachableSentinel_t)  //always true olacak
*/

std::string read_from_file(const char* pfile_name);

int main()
{
	const auto str = read_from_file("bigfile.txt");
	auto iter = std::ranges::find(str.begin(), UnReachableSentinel_t, '\n');
}
