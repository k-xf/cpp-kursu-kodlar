Fonksiyonun basitleştirilmiş bildirimi şöyle:

```
future async(std::launch, F func, args...);
```

Birinci parametre _launch policy_. <br>
_enum class launch_. (bitsel işlemlere uygun tür)


## Bu parametreye std::launch::async geçilirse

```
future async(std::launch::async, F func, args...)
```

+ _func_ fonksiyonunu _args_ argümanları ile asenkron _(paralel thread olarak)_ olarak başlatmaya çalışır.  
+ _func_ asenkron olarak çalıştırılamaz ise _std::system_error_ sınıfı türünden bir hata gönderilir.
  + Gönderilen hata kodu _std::errc::resource_unavailable_try_again_ 

+ Program anormal _(abnormal)_ sonlandırılmadıkça (std::abort ile sonlandırılmadıkça) başlatılan _thread_ program sonlanmadan önce mutlaka bitirilir.

+ _thread_ nasıl sonlanır?
  + geri döndürülen _future_ nesnesinin _get_ üye fonksiyonu çağrıldığında
  + geri döndürülen _future_ nesneninin _wait_ üyefonksiyonu çağrıldığında

## Bu parametreye std::launch::deferred geçilirse

```
future async(std::launch::deferred, F func, args...)
```
+ Bu durumda geri dönüş değeri olan _future_ nesnesinin _wait()_ ya da _get()_ fonksiyonlarından biri çağrıldığında _func_ işlevi senkron olarak çağrılacak.

## Bu std::launch parametresi yok ise

```
future async(F func, args...)
```
+ Bu durumda geri dönüş değeri olan _future_ nesnesinin _wait()_ ya da _get()_ fonksiyonlarından biri çağrıldığında _func_ senkron olarak çağrılacak.
