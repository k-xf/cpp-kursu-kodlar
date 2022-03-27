// boş bir std::function nesnesi ile çağrı yaparsak
// std::bad_function_call türünden exception throw eder.

#include <functional>
#include <iostream>

int main()
{
	std::function<int(int)> fnc;

	try {
		auto x = fnc(13);
	}
	//catch (const std::exception& ex) {
	catch (const std::bad_function_call& ex) {
		std::cout << "hata yakalandi : " << ex.what() << "\n";
		std::cout << typeid(ex).name() << "\n";
	}
}
