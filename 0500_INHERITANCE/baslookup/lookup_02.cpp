class Base {
public:
	void func(int) {}
};

class Der : public Base {
public:
	void func() 
	{
		func(); //gecerli - ozyinelemeli cagri
		//func(10); //gecersiz
		Base::func(10); //gecerli
	}
};
