namespace A {
	void f();
}

namespace B {
	void f();
}

void func()
{
	using A::f; //valid
	using B::f; //valid
        f(); //invalid - ambiguity
}
