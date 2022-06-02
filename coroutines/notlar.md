#### coroutines

* _coroutine_ kendi çalışmasını durdurabilen _(suspend)_ daha sonra çalışması tekrar devam ettirilebilen bir fonksiyon. Bu açıdan bakarsak fonksiyonları 2 kategoriye ayırabiliriz:
  * _subroutines_ (normal fonksiyonlar)
  * _coroutines_ (çalışması durdurulup sonra tekrar devam ettirilebilen fonksiyonlar)

* Bir fonksiyonun _coroutine_ olup olmadığı bildiriminden değil tanımından _(implementation)_ anlaşılıyor. Eğer fonksiyon tanımı içinde aşağıdaki anahtar sözcüklerden biri var ise derleyici söz konusu fonksiyonu bir _coroutine_ olarak ele alıyor:
 * co_await
 * co_yield
 * co_return
