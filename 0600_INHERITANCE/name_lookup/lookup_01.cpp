class Base {
public:
	void func(int) {}
};

class Der : public Base {
public:
	void func() {}
};

int main()
{
	Der myder;

	myder.func(); //gecerli
	//myder.func(10); //gecersiz
	myder.Base::func(10); //gecerli
}
