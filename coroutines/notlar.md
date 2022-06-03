#### coroutines
* _coroutin_'ler _1958_ yılında _Mel Konvoy_ tarafından icad edildi. 
* _C++20_ standartları ile dile bu konuda eklemeler yapıldı. Hem dile bazı temel araçlar _(core features)_ hem de standart kütüphaneye bazı öğeler eklendi. 
Ancak yine de bu araçtan faydalanmak için en basit kullanım senaryolarında dahi bazı bileşenlerin programcılar tarafından yazılması gerekiyor. 
C++23 ile standart kütüphaneye destekleyici bazı öğelerin eklenmesi planlanıyor.
  
* _coroutine_ kendi çalışmasını durdurabilen _(suspend)_ daha sonra çalışması tekrar devam ettirilebilen bir fonksiyon. Bu açıdan bakarsak fonksiyonları 2 kategoriye ayırabiliriz:
  * _subroutines_ (normal fonksiyonlar)
  * _coroutines_ (çalışması durdurulup sonra tekrar devam ettirilebilen fonksiyonlar)

* normal fonksiyonlar, çağrıldıkları zaman kodlarının tamamı çalışıyor. Yani fonksiyonun çalışması ya bir _return_ deyimi ile ya da bir _exception_ gönderilmesi ile sonlanıyor. Oysa bir _coroutine_ birden fazla adıma bölünerek çalıştırılabiliyor. Yani fonksiyonun çalışması durdurulup _(suspend)_ tekrar başlatılabiliyor.

* Bir fonksiyonun _coroutine_ olup olmadığı bildiriminden değil tanımından _(implementation)_ anlaşılıyor. Eğer fonksiyon tanımı içinde aşağıdaki anahtar sözcüklerden biri var ise derleyici söz konusu fonksiyonu bir _coroutine_ olarak ele alıyor:
 * co_await
 * co_yield
 * co_return

* Neden bir fonksiyonu bu şekilde çalıştırmak isteyelim? 
  * Fonksiyon belirli bazı işlemleri gerçekleştirdikten sonra işine devam etmek için bazı başka işlemlerin yapılmasını bekleyebilir.
  * Fonksiyon belirli bir basamakta elde ettiği ara veri ya da verileri kendisini çağıran fonksiyona iletebilir.

* Bir _coroutine_ çağırdığımızda onun kodunu basamaklar _(steps)_ halinde çalıştırabiliyoruz. Bu paralel çalıştırma (parallelism) ile karıştırılmamlı. (ping pong oyunu gibi düşünebiliriz)
* Hem ana kontrol akışı hem de _coroutine_'in kendi kontrol akışı aynı thread içinde gerçekleşiyor._multi-thread_ programlama ya da eş zamanlı erişim oluşturmak zorunda değiliz. Ancak _coroutine_'leri farklı _thread_'lerde çalıştırmak da mümkün.

* Coroutin'ler için C++20 itibarıyla aşağıdaki kısıtlamalar söz konusu:
  * bir _coroutine_ içinde _return statement_ kullanılamaz. Yalnızca _co_return statement_ kullanılabilir. ancak _co_return statement_ kullanılması zorunlu değil.
  * _coroutine_ C tarzı bir variadic fonksiyon olamaz.
  * _coroutine constexpr_ fonksiyon olamaz
  * bir constructor ya da destructor _coroutine_ olamaz.
  * _main_ fonksiyonu coroutine olamaz.
  * _coroutine_ bildiriminde _auto return type_ kullanılmaz.



