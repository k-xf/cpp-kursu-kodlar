#include <string>
#include <iostream>

int main()
{
	std::string s;
	s.reserve(700'000);
	auto cap = s.capacity();
	int alloc_cnt{};

	for (int i = 0; i < 1'000'000; ++i) {
		s.push_back('a');
		auto new_cap = s.capacity();
		if (new_cap > cap) {
			std::cout << ++alloc_cnt << ". reallocation size : " << s.size() << "  capacity : " << s.capacity() << '\n';
			cap = new_cap;
		}
	}
}
