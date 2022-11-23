int y = 0;

class Encloser {	// enclosing class (kapsayan sinif)
	int x;			// x kapsayan sinifin private non-static ogesi
	static int s;   // s kapsayan sinifin private static ogesi
public:
	struct Nested {		// icsel (gomulu) sinif
		void func(int ival)
		{
			//x = ival; // Gecersiz. ival non-static member
			int a = sizeof x; // C++11'den once gecersizdi
							  // C++11 ve sonrasinda gecerli sizeof operatorunun operandi olan ifade icin islem kodu üretilmiyor
							  // this use of the non-static enclose::x is allowed.

			s = ival;   // Kapsayan sınıfın static veri ogesine erisebilir
			::y = ival; // global degiskenlere erisebilir
			y = ival;   // global degiskenlere erisebilir
		}

		void foo(Encloser* p, int i)
		{
			p->x = i;	//ok, private ogeye erisebilir
		}
	};
};
