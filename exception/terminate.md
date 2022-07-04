#### Hangi durumlarda std::terminate işlevi çağrılır:

+ Bir _exception_ gönderildiğinde ve gönderilen _exception_ yakalanamadığında _(uncaught exception)_.
+ _noexcept_ olarak bildirilen bir fonksiyondan bir _exception_ gönderildiğinde. _(noexcept violation)_
+ gönderilen _exception_ kopyalama semantiği ile yakalandığında ve gönderilen _exception_ nesnesinin _copy ctor_'ı _exception throw_ ettiğinde.
