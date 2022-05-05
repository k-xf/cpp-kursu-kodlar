#### std::lock_guard
sınıfın _ctor_'ı _mutex_'i kilitliyor. Sınıfın destructor'ı kilidi açıyor.

#### scoped_lock 
_std::lock_guard_ sınıfına benziyor. Ancak sınıfın _constuctor_'ı birden fazla _mutex_ nesnesini alabiliyor. _constructor_ aldığı sırayla _mutex_ nesnelerini kilitliyor. destructor ters sırada kilitleri açıyor.

