#include <memory>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	unique_ptr<string[]> upx{ new string[4]{"ali", "veli", "can", "gul"} };
}
