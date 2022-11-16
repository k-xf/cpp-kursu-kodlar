#include <iostream>

class A {
public:
	A()
	{
		std::cout << "A()\n";
	}

	A(int val) : mx{ val }
	{
		std::cout << "A(int)\n";
	}

	~A()
	{
		std::cout << "~A()\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const A& a)
	{
		return os << "(A : " << a.mx << ")";
	}
private:
	int mx = 0;
};


class B {
public:
	B()
	{
		std::cout << "B()\n";
	}

	B(int val) : mx{ val }
	{
		std::cout << "B(int)\n";
	}

	~B()
	{
		std::cout << "~B()\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const B& b)
	{
		return os << "(B: " << b.mx << ")";
	}
private:
	int mx = 0;
};

A ax(10);
B bx(10);

#include <variant>

int main()
{
	std::cout << "main basliyor\n";
	std::cout.setf(std::ios::boolalpha);
	std::variant<A, B> var_ab(ax);

	std::cout << std::get<0>(var_ab) << "\n";
	std::cout << "A turunden nesne tutuyor: " << std::holds_alternative<A>(var_ab) << "\n";
	std::cout << "B turunden nesne tutuyor: " << std::holds_alternative<B>(var_ab) << "\n";

	std::cout << "index degeri : " << var_ab.index() << "\n";
	var_ab = bx;

	std::cout << "A turunden nesne tutuyor: " << std::holds_alternative<A>(var_ab) << "\n";
	std::cout << "B turunden nesne tutuyor: " << std::holds_alternative<B>(var_ab) << "\n";

	std::cout << "index degeri : " << var_ab.index() << "\n";
}
