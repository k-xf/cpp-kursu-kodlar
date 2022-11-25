#include <string>
#include <iostream>


template<typename Printable>
struct RepeatPrint
{
    void repeat(unsigned int n) const
    {
        while (n-- > 0)
        {
            static_cast<Printable const&>(*this).print();
        }
    }
};

class Name : public RepeatPrint<Name>
{
public:
    Name(std::string firstName, std::string lastName)
        : m_first_name(std::move(firstName))
        , m_last_name(std::move(lastName)) {}

    void print() const
    {
        std::cout << m_last_name << ", " << m_first_name << '\n';
    }

private:
    std::string m_first_name;
    std::string m_last_name;
};

int main()
{
    Name ned("Necati", "Ergin");
    ned.repeat(10);
}
