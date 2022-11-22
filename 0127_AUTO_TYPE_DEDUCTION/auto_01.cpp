#include <initializer_list>


int main()
{
	auto x1 = 10; //int x1 = 10;
	auto x2(10); //int x2(10);
	auto x3{10}; //int x3{10}
	auto x4 = { 10 }; //std::initializer_list<int> x4 = {10};
	auto x5 = { 10, 20 }; //std::initializer_list<int> x5 = {10, 20};
	//auto x6 = { 10, 2.0 }; //ambiguity error
	//auto x7{ 10, 20}; //error
}
