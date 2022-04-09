
namespace nec {
	void foo();
}

class Myclass {
	
public:
	friend void foo()
	{
		using nec::foo;
		foo();  //nec::foo
	}
};
