#### coroutines
* _coroutin_'ler _1958_ yılında _Mel Konvoy_ tarafından icad edildi. 
  
* _coroutine_ kendi çalışmasını durdurabilen _(suspend)_ daha sonra çalışması tekrar devam ettirilebilen bir fonksiyon. Bu nedenle _coroutine_'lere _"resumable function"_ da deniyor. Bu açıdan bakarsak fonksiyonları 2 kategoriye ayırabiliriz:
  * _subroutines_ (normal fonksiyonlar)
  * _coroutines_ (çalışması durdurulup sonra tekrar devam ettirilebilen fonksiyonlar)
  
* _C++20_ standartları ile dile bu konuda eklemeler yapıldı. Hem dile bazı temel araçlar _(core features)_ hem de standart kütüphaneye bazı öğeler eklendi. 
Ancak yine de bu araçtan faydalanmak için en basit kullanım senaryolarında dahi bazı bileşenlerin programcılar tarafından yazılması gerekiyor. 
C++23 ile standart kütüphaneye destekleyici bazı öğelerin eklenmesi planlanıyor.

* normal fonksiyonlar, çağrıldıkları zaman kodlarının tamamı çalışıyor. Yani fonksiyonun çalışması ya bir _return_ deyimi ile ya da bir _exception_ gönderilmesi ile sonlanıyor. Oysa bir _coroutine_ birden fazla adıma bölünerek çalıştırılabiliyor. Yani fonksiyonun çalışması durdurulup _(suspend)_ tekrar başlatılabiliyor. Bu işlem akışı birden fazla kez gerçekleştirilebiliyor.

* Neden bir fonksiyonu bu şekilde çalıştırmak isteyelim? 
  * Fonksiyon belirli bazı işlemleri gerçekleştirdikten sonra işine devam etmek için bazı başka işlemlerin yapılmasını bekleyebilir.
  * Fonksiyon belirli bir basamakta elde ettiği ara veri ya da verileri kendisini çağıran fonksiyona iletebilir.

* Bir _coroutine_ çağırdığımızda onun kodunu basamaklar _(steps)_ halinde çalıştırabiliyoruz. 
Bu paralel çalıştırma (parallelism) ile karıştırılmamlı. 
(ping pong oyunu gibi düşünebiliriz.)
* Hem ana kontrol akışı hem de _coroutine_'in kendi kontrol akışı aynı thread içinde gerçekleşiyor. 
_multi-thread_ programlama ya da eş zamanlı erişim oluşturmak zorunda değiliz. 
Ancak _coroutine_'leri farklı _thread_'lerde çalıştırmak da mümkün.
* Genel olarak programlama dillerindeki coroutine'ler iki ana kategoriye ayrılıyor:
	* stackless coroutine'ler
        * stackful  coroutine'ler
C++ dili _stackless coroutin_'ler sunuluyor.

* C++ dilinde, bir fonksiyonun _coroutine_ olup olmadığı bildiriminden değil tanımından _(implementation)_ anlaşılıyor. Yani bir fonksiyonun sadece bildirimine bakarak onun _coroutine_ olup olmadığını anlayamıyoruz. Eğer fonksiyon tanımı içinde aşağıdaki anahtar sözcüklerden biri var ise derleyici söz konusu fonksiyonu bir _coroutine_ olarak ele alıyor:
 * co_await
 * co_yield
 * co_return

Ancak bir fonksiyonun _coroutine_ olabilmesi için geri dönüş türünün bazı şartları sağlaması gerekiyor.



* _Coroutine_'ler için C++20 itibarıyla aşağıdaki kısıtlamalar söz konusu:
  * bir _coroutine_ içinde _return statement_ kullanılamaz. Yalnızca _co_return _ya da_ co_yield statement_ kullanılabilir. ancak _co_return statement_ kullanılması zorunlu değil.
  * _coroutine_ C tarzı bir _variadic_ fonksiyon olamaz.
  * _coroutine constexpr_ fonksiyon olamaz
  * bir constructor ya da destructor _coroutine_ olamaz.
  * _main_ fonksiyonu _coroutine_ olamaz.
  * _coroutine_ bildiriminde _auto return type_ kullanılmaz.

#### Derleyici bir coroutine için nasıl bir kod üretiyor?.
* Bu konu bir hayli karmaşık. Öncelikle derleyicinin, programcı tarafından tanımlanacak bazı sınıflara ve fonksiyonlara güvenerek kod ürettiğini söyleyerek başlayayım. Standart kütüphane şimdilik doğrudan kullanılacak bazı sınıflar sunmuyor. _C++23_ standartları ile standart kütüphaneye yeni sınıfların ve fonksiyonların ekleneceği belirtiliyor. Konunun daha iyi anlaşılmasına fayda sağlayacağını düşündüğümden coroutine'lerin gerçekleştiriminde kullanılan bileşenlerin her birini daha sonra ayrı ayrı ele alacağım.

* Derleyicinin _coroutine_ için bir _"coroutine frame"_ oluşturması gerekiyor. Bunun için bir bellek alanına ihtiyacı var. _coroutine frame_'de hangi bilgiler tutuluyor?
  * _coroutine_ parametre değişkenleri
  * tüm yerel değişkenler
  * bazı geçici nesneler
  * _coroutine_ suspend edildiğindeki _excecution state_ (_register'lar instruction pointer_ vs.)
  * çağıran koda iletilecek değer ya da değerleri tutacak olan bir _promise_ nesnesi.

* Genel olarak _coroutine frame_ dinamik olarak edinilmek zorunda. _coroutine suspend_ edildiğinde (durdurulduğunda) _stack_ erişimini kaybediyor. _coroutine frame_'in oluşturulması için _operator new_ kullanılıyor. Ancak farklı ihtiyaçlar için _operator new_ yüklenebiliyor (overload edilebiliyor).

* _coroutine frame_ _coroutine_'in çalıştırılmaya başlanmasından önce oluşturuluyor. (normal fonksiyonlarda _stack frame_'in oluşturulması gibi). Derleyici _coroutine frame_'i,  çağıran koda,  coroutine frame'e erişimi sağlayacak bir _handle_ döndürüyor (ama doğrudan değil)

#### coroutine handle
Peki _coroutine frame_'e nasıl erişeceğiz? Standart kütüphane bu amaçla bize _std::corutine_handle_ sınıf şablonunu sunuyor. Bu sınıfı iyi anlamalıyız:
```
template<typename T = void>
struct coroutine_handle;

template<>
struct coroutine_handle<void> {
	coroutine_handle()noexcept = default;
	coroutine_handle(std::nullptr_t)noexcept;
	coroutine_handle& operator=(std::nullptr_t)noexcept;
	explicit operator bool()const noexcept;
	static coroutine_handle from_address(void* adr)noexcept;
	void* to_address()const noexcept;
	void resume()const;
	void destroy();
	bool done()const;
};

template <typename Promise>
struct coroutine_handle : coroutine_handle<Promise> {
	Promise& promise()const noexcept;
	static coroutine_handle from_promise(Promise&)noexcept;
};
```

* Yukarıdaki koddan görülebileceği gibi _std::coroutine<T>_ sınıf şablonunun __void__ açılımı _(specialization)_ için bir _explicit specalization_ verilmiş.
 Diğer tür argümanları ile oluşturulacak sınıflar _coroutine_handle<void>_ sınıfından kalıtım yoluyla elde ediliyorlar. 

 
#### co_await için nasıl bir kod üretiliyor?

Bir _co_await_ ifadedsinin aşağıdaki gibi kullanıldığını düşünelim:

```auto result = co_await expr;```





