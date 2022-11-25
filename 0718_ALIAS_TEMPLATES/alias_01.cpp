template<typename T>
using Ptr = T*;

template<typename T>
using Cptr = const T*;

int main()
{
	int x = 10;
	Ptr<int> p{ &x };
	*p = 20;
	Cptr<int> cp{ &x };
	//*cp = 345; //invalid code
}
