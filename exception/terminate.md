#### Hangi durumlarda std::terminate işlevi çağrılır:

+ Bir _exception_ gönderildiğinde ve gönderilen _exception_ yakalanamadığında _(uncaught exception)_.
+ _noexcept_ olarak bildirilen bir fonksiyondan bir _exception_ gönderildiğinde. _(noexcept violation)_
