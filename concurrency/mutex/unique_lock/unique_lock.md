
_std::unique_lock_ <mutex> başlık dosyasında tanımlanan bir sınıf şablonu.
```
template <class Mutex>
class unique_lock;
```
The class unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking, time-constrained attempts at locking, recursive locking, transfer of lock ownership, and use with condition variables.

The class unique_lock is movable, but not copyable -- it meets the requirements of MoveConstructible and MoveAssignable but not of CopyConstructible or CopyAssignable.

The class unique_lock meets the BasicLockable requirements. If Mutex meets the Lockable requirements, unique_lock also meets the Lockable requirements (ex.: can be used in std::lock); if Mutex meets the TimedLockable requirements, unique_lock also meets the TimedLockable requirements.
