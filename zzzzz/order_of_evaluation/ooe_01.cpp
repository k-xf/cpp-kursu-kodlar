#include <iostream>

int f1()
{
	return 1;
}

int f2()
{
	return 2;
}

int f3()
{
	return 3;
}

int main()
{
	std::cout << f1() << f2() << f3() << "\n";
	//C++ 17 standartları ile fonksiyonların
	//f1 f2 f3 sırasıyla çağrılması garanti altında. Daha önce böyle bir garanti yoktu
}
