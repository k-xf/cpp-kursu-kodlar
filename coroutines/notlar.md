#### coroutines
* _coroutin_'ler _1958_ yılında _Mel Konvoy_ tarafından icad edildi. 
* _C++20_ standartları ile dile bu konuda eklemeler yapıldı. Hem dile bazı temel araçlar _(core features)_ hem de standart kütüphaneye bazı öğeler eklendi. 
Ancak yine de bu araçtan faydalanmak için en basit kullanım senaryolarında dahi bazı bileşenlerin programcılar tarafından yazılması gerekiyor. 
C++23 ile standart kütüphaneye destekleyici bazı öğelerin eklenmesi planlanıyor.
  
* _coroutine_ kendi çalışmasını durdurabilen _(suspend)_ daha sonra çalışması tekrar devam ettirilebilen bir fonksiyon. Bu açıdan bakarsak fonksiyonları 2 kategoriye ayırabiliriz:
  * _subroutines_ (normal fonksiyonlar)
  * _coroutines_ (çalışması durdurulup sonra tekrar devam ettirilebilen fonksiyonlar)

* Bir fonksiyonun _coroutine_ olup olmadığı bildiriminden değil tanımından _(implementation)_ anlaşılıyor. Eğer fonksiyon tanımı içinde aşağıdaki anahtar sözcüklerden biri var ise derleyici söz konusu fonksiyonu bir _coroutine_ olarak ele alıyor:
 * co_await
 * co_yield
 * co_return
