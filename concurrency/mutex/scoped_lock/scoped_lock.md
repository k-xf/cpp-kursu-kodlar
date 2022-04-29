_std::scoped_lock_ basically provides the same feature as _std::lock_guard_, but is more generic: 
It can lock several mutexes at the same time, with a deadlock prevention mechanism.
The equivalent code to perform simultaneous locking with std::lock_guard is significantly more complex.
Therefore, it is simpler to use std::scoped_lock all the time, even when locking only one mutex (there will be no performance impact).
