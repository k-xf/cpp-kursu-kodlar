#include <iostream>
#include <memory>
#include "triple.h"

int main()
{
	using namespace std;
	
	cout << "main basladi\n";

	{
		unique_ptr<Triple> upx{ new Triple{10, 20, 30} };

		cout << (upx ? "dolu" : "bos") << "\n";
		cout << *upx << "\n";
		upx->set(3, 6, 7);
		cout << *upx << "\n";
		cout << "blok sonu\n";
	}

	cout << "main devam ediyor\n";
}
