#### coroutines
* _coroutin_'ler _1958_ yılında _Mel Konvoy_ tarafından icad edildi. 
  
* _coroutine_ kendi çalışmasını durdurabilen _(suspend)_ daha sonra çalışması tekrar devam ettirilebilen bir fonksiyon. Bu nedenle _coroutine_'lere _"resumable function"_ da deniyor. Bu açıdan bakarsak fonksiyonları 2 kategoriye ayırabiliriz:
  * _subroutines_ (normal fonksiyonlar)
  * _coroutines_ (çalışması durdurulup sonra tekrar devam ettirilebilen fonksiyonlar)
  
* _C++20_ standartları ile dile bu konuda eklemeler yapıldı. Hem dile bazı temel araçlar _(core features)_ hem de standart kütüphaneye bazı öğeler eklendi. 
Ancak yine de bu araçtan faydalanmak için en basit kullanım senaryolarında dahi bazı bileşenlerin programcılar tarafından yazılması gerekiyor. 
C++23 ile standart kütüphaneye destekleyici bazı öğelerin eklenmesi planlanıyor. [Bu araçlar dile eklenene kadar bu amaçla _Lewis Baker_ tarafından geliştirilen _cppcoro_](https://github.com/lewissbaker/cppcoro) kütüphanesi kullanılabilir.

* Çağrılan (normal) fonksiyonların kodlarının tamamı çalışıyor. 
Yani bir fonksiyonun çalışması ya bir _return_ deyimi ile ya da bir _exception_ gönderilmesi ile sonlanıyor. 
Oysa bir _coroutine_ birden fazla adıma bölünerek çalıştırılabiliyor. 
Yani fonksiyonun çalışması durdurulup _(suspend)_ tekrar başlatılabiliyor. 
Bu işlem akışı (fonksiyonun kodunun durdurulup tekrar çalıştırılması) birden fazla kez gerçekleştirilebiliyor.

* Neden bir fonksiyonu bu şekilde çalıştırmak isteyelim? 
  * Fonksiyon belirli bazı işlemleri gerçekleştirdikten sonra işine devam etmek için bazı başka işlemlerin yapılmasını bekleyebilir.
  * Fonksiyon belirli bir basamakta elde ettiği ara veri ya da verileri kendisini çağıran fonksiyona iletebilir.

* Bir _coroutine_ çağırdığımızda onun kodunu basamaklar _(steps)_ halinde çalıştırabiliyoruz. 
Bu paralel çalıştırma _(parallelism)_ ile karıştırılmamalı. 
(ping pong oyunu gibi düşünebiliriz.)
* Hem ana kontrol akışı hem de _coroutine_'in kendi kontrol akışı aynı _thread_ içinde gerçekleşiyor. 
_multi-thread_ programlama ya da eş zamanlı erişim oluşturmak zorunda değiliz. 
Ancak _coroutine_'leri farklı _thread_'lerde çalıştırmak da mümkün.
* Genel olarak programlama dillerindeki coroutine'ler iki ana kategoriye ayrılıyor:
	- _stackless coroutine_'ler
	- _stackful coroutine_'ler
C++ dili _stackless coroutin_'ler sunuluyor.

* C++ dilinde, bir fonksiyonun _coroutine_ olup olmadığı bildiriminden değil tanımından _(implementation)_ anlaşılıyor. 
Yani bir fonksiyonun sadece bildirimine bakarak onun _coroutine_ olup olmadığını anlayamıyoruz. 
Eğer fonksiyon tanımı içinde aşağıdaki anahtar sözcüklerden biri var ise derleyici söz konusu fonksiyonu bir _coroutine_ olarak ele alıyor:
 * co_await
 * co_yield
 * co_return

Ancak bir fonksiyonun _coroutine_ olabilmesi için geri dönüş türünün bazı şartları sağlaması gerekiyor.

#### kısıtlamalar
_Coroutine_'ler için _C++20_ standartları itibarıyla aşağıdaki kısıtlamalar söz konusu:
* bir _coroutine_ içinde _return statement_ kullanılamaz. Yalnızca _co_return_ ya da _co_yield_ _statement_ kullanılabilir. ancak _co_return statement_ kullanılması zorunlu değil.
* _coroutine_ C tarzı bir _variadic_ fonksiyon olamaz.
* _coroutine constexpr_ ya da _consteval_ fonksiyon olamaz
* bir _constructor_ ya da _destructor_ _coroutine_ olamaz.
* _main_ fonksiyonu _coroutine_ olarak tanımlanamaz.
* _coroutine_ bildiriminde _auto return type_ kullanılmaz.

#### Derleyici bir coroutine için nasıl bir kod üretiyor?.
* Bu konu bir hayli karmaşık. Öncelikle derleyicinin, programcı tarafından tanımlanacak bazı sınıflara ve fonksiyonlara güvenerek kod ürettiğini söyleyerek başlayayım. Standart kütüphane şimdilik doğrudan kullanılacak bazı sınıflar sunmuyor. _C++23_ standartları ile standart kütüphaneye yeni sınıfların ve fonksiyonların ekleneceği belirtiliyor. Konunun daha iyi anlaşılmasına fayda sağlayacağını düşündüğümden _coroutine_'lerin gerçekleştiriminde kullanılan bileşenlerin her birini daha sonra ayrı ayrı ele alacağım.

* Öncelikle derleyicininürettiği kodda _coroutine_ için bir _"coroutine frame"_ oluşturulması gerekiyor. 
Bunun için bir bellek alanına ihtiyacı var. _coroutine frame_'de hangi bilgiler tutuluyor?
  * _coroutine_ parametre değişkenlerinin kopyaları
  * tüm yerel değişkenler
  * bazı geçici nesneler
  * _coroutine_ suspend edildiğindeki _excecution state_ (_register'lar instruction pointer_ vs.)
  * Çağıran koda iletilecek değer ya da değerleri tutacak olan bir _promise_ nesnesi. _promise_ Derleyicinin üretteceği kod belirli noktalarda bu _promise_ nesnesinin
üye fonksiyonlarını çağırıyor. 
* Genel olarak _coroutine frame_ dinamik olarak edinilmek zorunda. 
_coroutine suspend_ edildiğinde (durdurulduğunda) _stack_ erişimini kaybediyor. 
_coroutine frame_'in oluşturulması için _operator new_ kullanılıyor. 
Ancak farklı ihtiyaçlar için _operator new_ yüklenebiliyor _(overload edilebiliyor)_.
* _coroutine frame_ _coroutine_'in çalıştırılmaya başlanmasından önce oluşturuluyor. 
(normal fonksiyonlarda _stack frame_'in oluşturulması gibi). 
Derleyici _coroutine frame_'i,  çağıran koda, _coroutine frame_'e erişimi sağlayacak bir _handle_ döndürüyor (ama doğrudan değil)

#### coroutine handle
Peki _coroutine frame_'e nasıl erişeceğiz? Standart kütüphane bu amaçla bize _std::corutine_handle_ isimli bir sınıf şablonu sunuyor. Bu sınıfı iyi anlamalıyız:
```
template<typename T = void>
struct coroutine_handle;

template<>
struct coroutine_handle<void> {
	coroutine_handle() noexcept = default;
	coroutine_handle(std::nullptr_t)noexcept;
	coroutine_handle& operator=(std::nullptr_t)noexcept;
	explicit operator bool()const noexcept;
	static coroutine_handle from_address(void* adr) noexcept;
	void* to_address()const noexcept;
	void resume()const;
	void destroy();
	bool done()const;
};

template <typename Promise>
struct coroutine_handle : coroutine_handle<void> {
	Promise& promise()const noexcept;
	static coroutine_handle from_promise(Promise&)noexcept;
};
```

* Yukarıdaki koddan görülebileceği gibi _std::coroutine<T>_ sınıf şablonunun __void__ açılımı _(specialization)_ için bir _explicit specalization_ verilmiş.
 Diğer tür argümanları ile oluşturulacak sınıflar _coroutine_handle<void>_ sınıfından kalıtım yoluyla elde ediliyorlar. 

#### promise nesnesi _(promise object)_

_promise_ nesnesi, _coroutine_'in yürütülmesi sırasında bazı noktalarda çağrılacak fonksiyonları implemente ederek _coroutine_'in davranışını kontrol ediyor.
_coroutine_'e yapılan her çağrıda _coroutine frame_ içinde bir _promise_ nesnesi hayata getiriliyor. 
Derleyici _coroutine_'in çalışması sırasında bazı noktalarda _promise_ nesnesinin bazı fonksiyonlarını çağırıyor. 	
* _promise_ nesnesi _coroutine frame_ içinde tutuluyor. 
* _promise_ nesnesi, _coroutine_ fonksiyonun içinden manipüle ediliyor. 
* _coroutine_ ürettiği değer ya da değerleri kendisini çağıran koda _promise_ nesnesini kullanarak iletiyor.

Derleyicinin ürettiği kodun kabaca şöyle olduğunu düşünebiliriz.

```
{
	co_await promise.initial_suspend();
	try {
	
		<body statements>
	}
	catch (...) {
		promise.unhandled_exception();
	}
FinalSuspend:
	co_await promise.final_suspend();
}
```

Bir _coroutine_ fonksiyon çağrıldığında _coroutine_ gövdesindeki kodların çalıştırılmaya başlmasaından önce birçok işlem yapılıyor. Bu açıdan _coroutine_ fonksiyonlar normal fonksiyonlardan farklı. Daha sonra detaylı olarak incelemek üzere şimdi kabaca hangi işlemlerin yapıldığına bir bakalım:

1. _coroutine frame_ için bellek alanı ediniliyor. Bunu gerçekleştirmek için _operarator new_ fonksiyonu çağrılıyor. 
Ama _operator new_ fonksiyonunu burada _overload_ etmek mümkün.
2. Fonksiyonun parametre değişkenleri _coroutine frame_'e kopyalanıyor.
3. _promise_ nesnesi için _constructor_ çağrılıyor. Yani _promise_ nesnesi hayata getiriliyor.
4. _promise_ nesnesinin _get_return_object_ isimli fonksiyonu çağrılıyor:
```
promise.get_return_object() ;
```
Bu fonksiyondan elde edilen geri dönüş değeri _coroutine_ ilk kez _suspend_ edildiğinde coroutine fonksiyona çağrı yapan koda gönderiliyor. 
Sonuç yerel bir değişkende tutuluyor.
			
5. _promise_ nesnesinin _initial_suspend()_ fonksiyonu çağrılıyor. Fonksiyonun geri dönüş değeri _co_await_ operatörünün operandı yapılıyor.

```
co_await promise.initial_suspend();
```
6. _promise.initial_suspend()_ ifadesi _resume_ edildiğinde (hemen ya da asenkron olarak) _coroutine_ gövdesindeki bizim yazdığımız kodlar çalışmaya başlıyor.

_coroutine_ kodu yürütüldüğünde bir _co_return_ deyimi ile karşılaşılırsa _promise_ nesnesinin _return_void_ ya da _return_value_ fonksiyonu çağrılıyor:

```
promise.return_void()
promise.return_value(<expr>)
```

Otomatik ömürlü tüm sınıf nesneleri (hayata geldikleri sıra ile ters sırada) yok ediliyor. Daha sonra _promise_ nesnesinin _final_suspend_ isimli fonksiyonu çağrılıyor. 
Bu çağrıdan elde edilen geri dönüş değeri _co_await_ operatörünü operandı yapılıyor:
```
co_await promise.final_suspend();
```

Programın çalışma zamanında _handle_ edilmeyen bir _exception_ olursa bu _exception_ yakalanıyor ve _catch_ bloğu içinden _promise_ nesnesinin _unhandled_exception_ isimli fonksiyonu çağrılır. Daha sonra _promise_ nesnesinin _final_suspend_ fonksiyonu çağrılıyor. Çağrılan fonksiyonun geri dönüş değeri _co_await_ operatörünün operandı yapılıyor.

```
co_await promise.final_suspend();
```

Programın akışı _coroutine_ gövdesinin dışına çıktığında _coroutine frame_ _destroy_ ediliyor. 
_coroutine frame_'in _destroy_ edilmesi birkaç basamakta gerçekleştiriliyor:

- önce _promise_ nesnesinin _destructor_'ı çağrılıyor.
- fonksiyon parametre değişkenlerinin oluşturulmuş kopyaları için _destructor_'lar çağrılıyor.
- _coroutine frame_ için edinilmiş bellek alanı _operator delete_ fonksiyonuna yapılan çağrı ile geri veriliyor.
- Programın akışı çağrıyı yapan çağrıyı _resume_ eden koda yönlendiriliyor.


```
co_await promise.final_suspend();
```

	
#### co_await için nasıl bir kod üretiliyor?
Bir _co_await_ ifadesinin aşağıdaki gibi kullanıldığını düşünelim:
```auto result = co_await expr;```
devam edecek...
	
#### Awaitables
- _co_await_ operatörünün ihtiyaç duyduğu operandlara _Awaitables_ deniyor. 
Yani _co_await_ operatörünü kullanabilmemiz için bir _Awaitable_ gerekiyor.
- Bir _Awaitable_ elde etmenin tipik biçimine _Awaiter_ deniyor.
_coroutine_'in _suspend_ ya da _resume_ olması için _awaiter_'ın 3 üye fonksiyona sahip olması gerekiyor. 





