#include <typeinfo>
#include <iostream>

class Base {
public:
	virtual ~Base() = default;
	//...
};

class Der1 : public Base {
	//...
};

class Der2 : public Der1 {
	//...
};

int main()
{
	Base* p = new Der2;

	std::cout << std::boolalpha;
	std::cout << (typeid(*p) == typeid(Base)) << '\n';  //false
	std::cout << (typeid(*p) == typeid(Der1)) << '\n';  //false
	std::cout << (typeid(*p) == typeid(Der2)) << '\n';  //false

	delete p;
}
