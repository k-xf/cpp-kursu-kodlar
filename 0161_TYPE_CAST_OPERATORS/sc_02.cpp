#include <iostream>

int main()
{
	int ival{ 10 };
	void* vp{ &ival };
	//

	int* ip = static_cast<int*>(vp);
	*ip = 34;
	std::cout << "ival = " << ival << "\n";
}
