class Myclass {
public:
	double foo(double);
};

int g{};
int foo(int);

template <int x>
class A {};

template <int *p>
class B {};

template <int (*pf)(int)>
class C { };

template <double(Myclass::*)(double)> 
class D{};

int main()
{
	A<5> ax;
	B<&g> bx;
	C<foo> cx;
	D<&Myclass::foo> dx;
	//
}
