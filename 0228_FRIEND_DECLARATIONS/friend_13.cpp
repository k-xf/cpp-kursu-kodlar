//friend fonksiyonlar ve isim arama

class Myclass {
	friend void foo(int)
	{
		//... 
		foo(12); //gecersiz foo ismi aranıyor bulunamiyor
		Myclass::foo(12); //gecersiz Myclass içinde bildirilmiş foo isimli bir member yok
	}
};
