//nec.h

class Nec {
public:
	void foo();
};

void Nec::foo()
{

}

/*
	Nec sınıfının foo isimli fonksiyonu inline değil.
	Bu başlık dosyası birden fazla kaynak dosya tarafından include edilirse 
	ODR ihlal edilmiş olacak
*/
