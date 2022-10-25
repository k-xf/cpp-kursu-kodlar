struct Nec {
	int x, y, z;
};


Nec foo();

void f1()
{
	//auto [a, b] = foo(); //gecersiz
}

void f2()
{
	auto [a, b, _] = foo(); //gecerli
	//...
}

void f3()
{
	//auto [a, _, _] = foo(); //gecersiz
}

void f4()
{
	auto [a, _, __] = foo(); //gecerli
	//...
}
