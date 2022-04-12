#include <iostream>

struct Data {
	int a;
	int b = 20;
	
	struct Nested {
		int x;
	}c;
};

int main()
{
	Data mydata{ 3 }; 
				
	std::cout << "mydata.a = " << mydata.a << "\nmydata.b = " << mydata.b << "\nmydata.c.x = " << mydata.c.x;  // 3  20  0
}
