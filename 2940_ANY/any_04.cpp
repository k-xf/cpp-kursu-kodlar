/*
	sınıfın reset üye fonksiyonu tutulan nesnenin ömrünü sonlandırıyor.
	sınıfın has_value fonksiyonu any nesnesinin bir değer tutup tutmadığını sorguluyor.
*/

#include <any>
#include <iostream>

int main()
{
	try {
		std::any any_val = 876;
		std::cout << "Deger:  " << std::any_cast<int>(any_val) << "\n";

		any_val.reset();
		if (!any_val.has_value())
			std::cout << "degisken bir degere sahip degil\n";

		auto ival = std::any_cast<int>(any_val); //hata gonderecek
	}
	catch (const std::bad_any_cast& e) {
		std::cout << "hata yakalandi: " << e.what() << "\n";
	}
}
