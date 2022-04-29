+ A recursive mutex is a mutex for which a thread may own multiple locks at the same time.
+ After a mutex is first locked by thread A, thread A can acquire additional locks on the mutex (without releasing the lock already held).
+ The mutex is not available to other threads until thread A releases all of its locks on the mutex.
+ A recursive mutex is typically used when code that locks a mutex must call other code that locks the same mutex (in order to avoid deadlock).
+ For example, a function that acquires a mutex and recursively calls itself (resulting in the mutex being relocked) would need to employ a recursive mutex.
+ A recursive mutex has more overhead than a nonrecursive mutex.
+ Code that uses recursive mutexes can often be more difficult to understand and therefore more prone to bugs.
+ Consequently, the use of recursive mutexes should be avoided if possible.
+ recursive mutexes provided by classes std::recursive_mutex and std::recursive_timed_mutex.
+ recursive_mutex class similar to std::mutex class except allows relocking.
+ recursive_timed_mutex class similar to std::timed_mutex class except allows relocking.
+ implementation-defined limit to number of levels of locking allowed by recursive mutex.
