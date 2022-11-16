#include <string>
#include <variant>
#include <iostream>

int main()
{
	try
	{
		using age_t = int;
		using weight_t = double;
		using name_t = std::string;

		std::variant<age_t, weight_t, name_t> va;

		enum : size_t { idx_age, idx_weight, idx_name };

		va = 19;

		std::cout << "yas     = " << std::get<idx_age>(va) << '\n';
		std::cout << "yas     = " << std::get<age_t>(va) << '\n';

		va = 3.14;

		std::cout << "agirlik = " << std::get<idx_weight>(va) << '\n';
		std::cout << "agirlik = " << std::get<weight_t>(va) << '\n';

		va = "Ahmet Soysal";

		std::cout << "isim    = " << std::get<idx_name>(va) << '\n';
		std::cout << "isim    = " << std::get<name_t>(va) << '\n';
	}
	catch (std::bad_variant_access& e)
	{
		std::cout << "hata yakalandi: " << e.what() << '\n';
	}

}
