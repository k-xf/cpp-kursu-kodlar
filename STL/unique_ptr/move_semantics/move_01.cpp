#include <iostream>
#include "triple.h"

int main()
{
	auto upx = std::make_unique<Triple>(10, 30, 56);

	std::cout << "upx = " << (upx ? "dolu" : "bos") << "\n";

	auto upy = move(upx);

	(void)getchar();

	std::cout << "upx = " << (upx ? "dolu" : "bos") << "\n";
	std::cout << "upy = " << (upy ? "dolu" : "bos") << "\n";
}
