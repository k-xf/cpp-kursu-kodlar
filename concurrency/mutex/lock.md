_std::lock_ fonksiyonu _<mutex>_ başlık dosyasında bildirilmiş:

```
template< class Lockable1, class Lockable2, class... LockableN >
void lock( Lockable1& lock1, Lockable2& lock2, LockableN&... lockn );
```

+ Bu fonksiyonu kullanarak birden fazla _mutex_'i _deadlock_ oluşturmadan edinebiliyoruz.

```
std::lock(mtx_1, mtx_2, mtx_3);
```

+ mutex'lerin edinilme sırası tanımlı değil. Yani argüman olarak gönderilen mutex'ler herhangi bir sırada edinilebilirler.
