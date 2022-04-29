**unique_lock lock;**  <br>
Default constructor; creates a lock not associated with a mutex.<br><br>
**unique_lock lock(mtx);**<br>
Creates a lock guard for the mutex mtx and locks it. <br><br>
**unique_lock lock(mtx, adopt_lock);**<br>
Creates a lock guard for the already locked mutex mtx.<br> <br>
**unique_lock lock(mtx, defer_lock);** <br>
 Creates a lock guard for the mutex mtx without locking it.<br><br>
**unique_lock lock(mtx, try_lock);<br>**
Creates a lock guard for the mutex mtx and tries to lock it. <br><br>
**unique_lock lock(mtx, dur);<br>**
Creates a lock guard for the mutex mtx and tries to lock it for duration dur.<br><br>
**unique_lock lock(mtx, p);<br>**
Creates a lock guard for the mutex mtx and tries to lock it until timepoint tp.<br><br>
**unique_lock lock(rv);<br>**
Move constructor; moves lock state from rv to l (rv has no associated mutex anymore).<br><br>
**lock.~unique_lock();**<br>
Unlocks the mutex, if any locked, and destroys the lock guard.<br><br>
**unique_lock lock = rv;<br>**
Move assignment; moves the lock state from rv to lock (rv has no associated mutex anymore).<br><br>
**swap(lock1, lock2);<br>**
Swaps locks.<br><br>
**lock1.swap(lock2);**<br>
Swaps locks.<br><br>
**lock.release();<br>**
Returns a pointer to the associated mutex and releases it.<br><br>
**lock.owns_lock();<br>**
Returns true if an associated mutex is locked.<br><br>
**if (lock)<br>**<br>
Checks whether an associated mutex is locked.<br><br>
**lock.mutex();<br>**
Returns a pointer to the associated mutex.<br><br>
**lock.lock();<br>**
Locks the associated mutex.<br><br>
**lock.try_lock();<br>**
Tries to lock the associated mutex (returns true if lock successful).<br><br>
**lock.try_lock_for(dur);<br>**
Tries to lock the associated mutex for duration dur (returns true if lock successful).<br><br>
**lock.try_lock_until(tp);<br>**
Tries to lock the associated mutex until timepoint tp (returns true if lock successful).<br><br>
**lock.unlock();<br>**
Unlocks the associated mutex.<br><br>




