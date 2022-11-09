#include <optional>

int main()
{
	std::optional<int> op{ 10 };

	op.value() = 20;
	op.value_or(0) = 30; //gecersiz
	//value_or islevi referans döndürmüyor.
	//...
}
