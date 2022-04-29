_std::scoped_lock_ basically provides the same feature as _std::lock_guard_, but is more generic: 
It can lock several mutexes at the same time, with a deadlock prevention mechanism.
The equivalent code to perform simultaneous locking with std::lock_guard is significantly more complex.
Therefore, it is simpler to use std::scoped_lock all the time, even when locking only one mutex (there will be no performance impact).

+ std::scoped_lock is RAII class for mutexes
+ declaration:
```
template <class... Mtx> 
class scoped_lock;
```
+ parameter pack Mtx specifies types of mutexes to be locked.
+ can be used with any mutex types providing necessary locking interface (e.g., std::mutex and std::recursive_mutex)
+ constructor takes one or more mutexes as arguments
+ mutexes acquired in constructor and released in destructor
+ scoped_lock objects are not movable and not copyable
+ using scoped_lock avoids problem of inadvertently failing to release mutexes (e.g., due to exception or forgetting unlock calls)
+ in multiple mutex case, employs deadlock avoidance algorithm from std::lock (discussed later) when acquiring mutexes
+ advisable to use scoped_lock instead of calling lock and unlock explicitly
+ scoped_lock effectively replaces (and extends) lock_guard
