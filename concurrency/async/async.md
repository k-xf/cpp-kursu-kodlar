```
int f1();
int f2();

int main()
{
	// f1() + f2() işleminin sonucuna ihtiyacımız var;
	auto n = f1() + f2(); 
	
	//bu durumda fonksiyonlar senkron çalışıyor. 
	// Tabi ki hangisinin önce çağrılacağı derleyiciye bağlı
	// n değerinin hesaplanma süresi f1() ve f2() fonksiyonlarının çalışma süresinin toplamı (+overhead)
}
```

Fonksiyonun basitleştirilmiş bildirimi şöyle:

```
future async(std::launch, F func, args...);
```

Birinci parametre _launch policy_. <br>
_enum class launch_. (bitsel işlemlere uygun tür)


#### Bu parametreye std::launch::async geçilirse

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

#### Bu parametreye std::launch::deferred geçilirse

```
future async(std::launch::deferred, F func, args...)
```
+ Bu durumda geri dönüş değeri olan _future_ nesnesinin _wait()_ ya da _get()_ fonksiyonlarından biri çağrıldığında _func_ işlevi senkron olarak çağrılacak.

## Bu std::launch parametresi yok ise

```
future async(F func, args...)
```
+ Bu durumda geri dönüş değeri olan _future_ nesnesinin _wait()_ ya da _get()_ fonksiyonlarından biri çağrıldığında _func_ senkron olarak çağrılacak.





#### bazı notlar
+ _std::async_ işlevine gönderilen _callable_'ın geri dönüş değeri yoksa bu durumda async fonksiyonunun geri dönüş değeri _std::future<void>_ türüdür.
+ _std::async_ işlevine gönderilen _callable_ çalıştırıldığında bir exception gönderirse bu exception yakalanabilir.

