#include <iostream>

using namespace std;

class Neco {

};


class Myclass {
public:
	Myclass(Neco x)
	{
		std::cout << "Myclass::Myclass(Neco)\n";
	}
};



int main()
{
	Myclass m1((Neco()));
	std::cout << "bir tusa basin: "; std::getchar();
	Myclass m2{ Neco() };
	Myclass m3(Neco{});
	Myclass m4(Neco());
}
