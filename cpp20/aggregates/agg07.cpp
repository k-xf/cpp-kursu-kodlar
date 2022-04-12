struct Data{
	int x,y;
	struct Nested {
		int a,b;
	}z;
};

int main()
{
	struct Data mydata = { 1,2,{3,4} }; // Valid

	struct Data mydata = { 1,2,3,4 }; // Valid

	struct Data mydata = (1, 2, 3, 4); // Syntax Error
}
