#include <iostream>


[[noreturn]] void foo();

int main()
{
	foo();
	std::cout << "necati"; //derleyici burada uyari verebilir
}
