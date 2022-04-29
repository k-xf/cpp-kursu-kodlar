+ _std::shared_lock_ is RAII class for shared mutexes
+ declaration:
```
template <class M>
class shared_lock;
```
template parameter _M_ specifies type of mutex (e.g., std::shared_mutex or std::shared_timed_mutex)
+ similar interface as std::unique_lock but uses shared locking
+ constructor may optionally acquire mutex
+ may acquire and release mutex many times throughout lifetime of object
+ destructor releases mutex if held
+ all operations mapped onto shared locking primitives (e.g., lock mapped to lock_shared, unlock mapped to unlock_shared)
+ for exclusive locking with shared mutexes, std::unique_lock and std::scoped_lock (and std::lock_guard) can be used
