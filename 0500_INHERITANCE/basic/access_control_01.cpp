
class Base {
	void foo_private() {}
protected:
	void foo_protected() {}
public:
	void foo_public() {}
};

class Der : public Base {
public:
	void derfunc()
	{
		// foo_private(); //gecersiz - (erisim kontrolu)
		foo_protected(); //gecerli
		foo_public(); //gecerli
	}
};

int main()
{
	Der myder;

	myder.foo_public();
	//myder.foo_private(); //gecersiz
	//myder.foo_protected(); //gecersiz
}


