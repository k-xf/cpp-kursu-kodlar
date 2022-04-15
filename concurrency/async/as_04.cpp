#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <future>


namespace {
	std::map<char, size_t> histogram(const std::string& s)
	{
		std::map<char, std::size_t> cmap;

		for (char c : s)
			++cmap[c];

		return cmap;
	}

	std::string get_sorted(std::string str)
	{
		sort(begin(str), end(str));
		erase_if(str, [](char c) {return isspace(c); });
		return str;
	}

	bool is_vowel(char c)
	{
		static const char vowels[]{ "AEIOUaeiou" };
		return std::find(std::begin(vowels), std::end(vowels), c) != std::end(vowels);
	}

	size_t count_vowels(const std::string& s)
	{
		return count_if(begin(s), end(s), is_vowel);
	}
}

int main()
{
	std::string sline;
	std::cout << "enter a string: ";

	getline(std::cin, sline);

	auto hist = async(std::launch::async, histogram, sline);
	auto sorted_str = async(std::launch::async, get_sorted, sline);
	auto vowel_count = async(std::launch::async, count_vowels, sline);

	for (const auto& [c, count] : hist.get()) {
		std::cout << c << ": " << count << '\n';
	}
	
	std::cout << "sorted string : "
		<< quoted(sorted_str.get()) << '\n'
		<< "total vowels: "
		<< vowel_count.get() << '\n';
}
