std::lock fonksiyonu <mutex> başlık dosyasında bildirilmiş:

```
template< class Lockable1, class Lockable2, class... LockableN >
void lock( Lockable1& lock1, Lockable2& lock2, LockableN&... lockn );
```
