struct A { int x, y; };

int main()
{
	struct A a = { .y = 1, .x = 3 }; // invalid
	int ar[] = { [2] = 6 }; // invalid
	struct B b = { .a.x = 10 }; // invalid
	struct A a2 = { .x = 5, 34 }; // invalid
	struct A a3 = { .x = 5, .x = 42 }; // invalid
}
