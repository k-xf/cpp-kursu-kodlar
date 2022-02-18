#include <typeinfo>
#include <iostream>

//typeid operatörünün operandı olan ifade "unevaluated context"

int main()
{
	int x = 10;
	auto p = typeid(x++).name();
	std::cout << "x = " << x << "\n"; //10
}
