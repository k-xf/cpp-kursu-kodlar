class Myclass {
	friend void foo(int)
	{
		std::cout << "friend foo\n";
	}

	void f()
	{
		foo(12);  //gecersiz
		//::foo(12);  //gecersiz
	}
};
