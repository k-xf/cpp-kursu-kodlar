namespace A {
	void f();
}

namespace B {
	void f();
}

void func()
{
	using A::f;
	using B::f; //gecerli
}
