class Base {
public:
	void func() {}
};

class Der : public Base {
	void func() {}
public:
};

int main()
{
	Der myder;

	//myder.func(); //gecersiz - erisim kontrolu
	myder.Base::func(); //gecerli
}
