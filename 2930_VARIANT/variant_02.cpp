#include <iostream>
#include <variant>

int main()
{
	std::variant<int, double> v1, v2;

	std::cout << std::get<int>(v1) << "\n";
	v1 = 12; //v1 int türden deger tutuyor.

	int& i = std::get<int>(v1);
	++i;
	std::cout << std::get<int>(v1) << "\n";
	std::get<int>(v1) = 20;
	std::cout << std::get<int>(v1) << "\n";

	v2 = std::get<int>(v1);
	v2 = std::get<0>(v1); // yukarıdaki ile aynı anlamda
	v2 = v1; // yukarıdaki ile aynı anlamda

	//auto f = std::get<float>(v1); // gecersiz: variant'ta tutulan float yok
	//auto x = std::get<3>(v1);      // gecersiz: yalnızca 0 ve 1 indeks degerleri geçerli

	try {
		double dval = std::get<double>(v2); // v2 double değil int tutuyor. exception throw edecek
	}
	catch (const std::bad_variant_access& ex) {
		std::cout << "hata yakalandi: " << ex.what() << "\n";
	}
}
