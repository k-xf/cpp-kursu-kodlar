#include "triple.h"
#include <memory>

int main()
{
	auto upx = std::make_unique<Triple>(10, 30, 56);
	std::cout << *upx << "\n";
	std::cout << (upx ? "dolu" : "bos") << "\n";
	upx.reset();
	//upx.reset(nullptr);
	std::cout << (upx ? "dolu" : "bos") << "\n";
	std::cout << "main devam ediyor\n";
}
