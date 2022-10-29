template<class T> 
struct A { 
	A(T, T); 
};

int main()
{
	auto pa = new A{ 1, 2 }; //new expression
	auto z = A(1.2, 5.6);  //function-style cast
}
