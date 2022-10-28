class Nec {
public:
	void func()&;
	Nec& operator=(const Nec&)& = default;
};

int main()
{
	Nec nec;

	nec.func(); //valid
	//Nec{}.func(); //invalid
	//Nec{} = nec; // invalid
}
