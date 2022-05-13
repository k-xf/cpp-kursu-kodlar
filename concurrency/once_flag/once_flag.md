+ sometimes may want to perform action only once in code executed in multiple threads.
+ can be achieved through use of std::once_flag type in conjunction with std::call_once template function.
+ std::once_flag class represents flag used to track if action performed.
+ declaration of _std::call_once_:
```
template <class Callable, class... Args>
void call_once(std::once_flag& flag, Callable&& f, Args&&... args);
```
+ std::call_once invokes f only once based on value of flag object.
+ first invocation of f is guaranteed to complete before any threads return from call_once.
+ useful for one-time initialization of dynamically generated objects.
