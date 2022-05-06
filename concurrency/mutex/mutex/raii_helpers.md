#### std::lock_guard
sınıfın kurcu işlevi _mutex_'i kilitliyor. Sınıfın sonlandırıcı işlevi kilidi açıyor.

#### std::scoped_lock 
_std::lock_guard_ sınıfına benziyor. Ancak sınıfın kurucu işlevi birden fazla _mutex_ nesnesini alabiliyor. Kurucu işlev aldığı sırayla _mutex_ nesnelerini kilitliyor. Sonlandırıcı işlev ters sırada kilitleri açıyor.

#### std::unique_lock
Locks a mutex in exclusive mode. The constructor also accepts arguments
that instruct it to timeout instead of blocking forever on the lock call.
It is also possible to not lock the mutex at all, or to assume that it is locked already, or to only try locking the mutex.
Additional methods allow to lock and unlock the mutex during the unique_lock lock’s lifetime.

#### std::shared_lock.
Same as unique_lock, but all operations are applied on the mutex in shared mode.
