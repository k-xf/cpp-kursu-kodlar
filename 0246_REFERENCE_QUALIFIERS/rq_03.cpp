class Nec {
public:
};

Nec foo();

int main()
{
	foo() = foo();
}
