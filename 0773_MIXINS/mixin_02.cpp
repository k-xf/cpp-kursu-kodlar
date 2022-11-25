#include <iostream>

template <typename Base>
class SkillA : public Base {
public:
	void afunc()
	{
		std::cout << "skill A is running\n";
		Base::foo(); 
		Base::bar();
		std::cout << "-----------------------------------------\n";
	}
};

template <typename Base>
class SkillB : public Base {
public:
	void bfunc()
	{
		std::cout << "skill B is running\n";
		Base::baz();
		Base::foo();
		std::cout << "-----------------------------------------\n";
	}
};

template <typename Base>
class SkillC : public Base {
public:
	void cfunc()
	{
		std::cout << "skill C is running\n";
		Base::foo();
		Base::foo();
		Base::foo();
		std::cout << "-----------------------------------------\n";
	}
};


class Myclass {
public:
	void foo()
	{
		std::cout << "Myclass::foo()\n";
	}

	void bar()
	{
		std::cout << "Myclass::bar()\n";
	}

	void baz()
	{
		std::cout << "Myclass::baz()\n";
	}
};


int main()
{
	//SkillA<Myclass>{}.afunc();
	//SkillB<Myclass>{}.bfunc();
	//SkillC<Myclass>{}.cfunc();

	SkillA<SkillB<SkillC<Myclass>>> x;

	x.afunc();
	x.bfunc();
	x.cfunc();
}
