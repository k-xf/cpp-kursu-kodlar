#include <string>
#include <iostream>

void print(const std::string& str)
{
	std::cout << "[" << str << "] [" << str.size() << "/" << str.capacity() << "]\n";
}

int main()
{
	//std::string s1('a'); //gecersiz char parametreli ctor yok
	std::string s2(65, 'A'); //fill ctor
	print(s2);
	std::string s3{ 65, 'A' }; //init_list ctor
	//string s3 = { 65, 'A' }; //init_list ctor
	print(s3);
}
