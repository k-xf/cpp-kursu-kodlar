#include <iostream>

class Base {
public:
	Base()
	{
		std::cout << "Base default ctor\n";
	}
	~Base()
	{
		std::cout << "Base destructor\n";
	}

};

class Der : public Base {
public:
	
};

int main()
{
	Der myder;
}
