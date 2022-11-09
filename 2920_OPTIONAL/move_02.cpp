#include <optional>
#include <iostream>

struct A {
	A() { std::cout << "default ctor()\n"; }
	A(const A&) = delete;
	A& operator=(const A&) = delete;
	A(A&&) { std::cout << "move ctor()\n"; }
	//...
};

int main()
{
	std::optional<A> op1;
	op1.emplace(); //default ctor
	std::optional<A> op2{ std::move(op1) }; //A's move ctor.
	std::cout << std::boolalpha;
	std::cout << op1.has_value() << "\n";
	std::cout << op2.has_value() << "\n";
}
