class Nec {
public:
	void func();
};

int main()
{
	Nec nec;

	nec.func(); //valid
	Nec{}.func(); //valid
	Nec{} = nec; // valid
}
