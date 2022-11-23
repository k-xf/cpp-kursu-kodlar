#include <iostream>

class Encloser {
	struct Nested 
	{
		void func() 
		{
			std::cout << "Nested::foo()\n";
		}
	};
public:
	static Nested make_Nested() 
	{
		return Nested();
	}
};

int main()
{
	//Encloser::Nested nx;   //erisim kontrolu
	//Encloser::Nested ny = Encloser::make_Nested();  //erisim kontrolu
	auto nes = Encloser::make_Nested();
	nes.func();
}
