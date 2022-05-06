_std::lock_ fonksiyonu _<mutex>_ başlık dosyasında bildirilmiş:

```
template< class Lockable1, class Lockable2, class... LockableN >
void lock( Lockable1& lock1, Lockable2& lock2, LockableN&... lockn );
```

+ Bu fonksiyonu kullanarak birden fazla _mutex_'i _deadlock_ oluşturmadan edinebiliyoruz.

```
std::lock(mtx_1, mtx_2, mtx_3);
```

+ _mutex_'lerin edinilme sırası tanımlı değil. Yani argüman olarak gönderilen _mutex_'ler herhangi bir sırada edinilebilirler.
+ içsel olarak argüman olarak gönderilen _mutex_'lerin _lock, try_lock_ ve _unlock_ fonksiyonları çağrılıyor.
+ _std::lock_ fonksiyonuna yapılan çağrı _thread_'i bloke ediyor.
+ _deadlock_ oluşmaması garantisi var.
