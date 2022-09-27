#include <string>
#include <iostream>


class Person{
public:
	Person()
	{
	std::cout << "Person() this     : " << this << '\n';
	}

	~Person()
	{
		std::cout << "Person() this     : " << this << '\n';
	}
	//...
private:
	long long m_id{};
	std::string m_name{};
	std::string m_address{};
};

int main()
{
	std::cout << "sizeof(Person)    : " << sizeof(Person) << '\n';
	char buffer[sizeof(Person)];

	std::cout << "address of buffer : " << &buffer << '\n';
	auto p = new(buffer)Person;
	std::cout << "p                 : " << &buffer << '\n';
	//delete p; //u.b.
	p->~Person();

}
