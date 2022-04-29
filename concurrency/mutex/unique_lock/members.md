**unique_lock lock;**  <br>
Default constructor; creates a lock not associated with a mutex.<br><br>
**unique_lock lock(mtx);**<br>
Creates a lock guard for the mutex mtx and locks it. <br><br>
**unique_lock lock(mtx, adopt_lock);**<br>
Creates a lock guard for the already locked mutex mtx.<br> <br>
**unique_lock lock(mtx, defer_lock);** <br>
 Creates a lock guard for the mutex mtx without locking it.<br><br>
**unique_lock lock(mtx, try_lock);<br>**
Creates a lock guard for the mutex m and tries to lock it. <br><br>



