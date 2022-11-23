
//call foo işlevinin geri dönüş değeri türü ne olmalı?

template<typename T>
??? callFoo(T&& arg)
{
    return foo(std::forward<T>(arg));
}
