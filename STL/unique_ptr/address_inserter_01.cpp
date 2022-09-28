#include <memory>
#include "triple.h"
#include <iostream>

int main()
{
	using namespace std;
	cout << "main basladi\n";
	Triple* ptr = new Triple{ 1, 2, 3 };
	cout << "ptr = " << ptr << '\n';
	unique_ptr<Triple> up{ ptr };
	cout << up << '\n';
	cout << up.get() << '\n';
}
