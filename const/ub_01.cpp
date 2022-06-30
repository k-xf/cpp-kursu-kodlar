//const nesnelerin değiştirilme girişimi tanımsız davranış

int main()
{
	const int x = 10;
	int* p = const_cast<int*>(&x);

	*p = 45;  //ub
}
