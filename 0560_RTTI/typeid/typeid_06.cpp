#include <typeinfo>
#include <iostream>

int main()
{
	//type_info sınıfının varsayılan kurucu islevi yok
	//type_info x; //gecersiz 

	//type_info sınıfının kopyalayan kurucuy işlevi delete edilmiş.
	//auto x = typeid(20); //gecersiz
}
