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

#### Bu std::launch parametresi yok ise

```
future async(F func, args...)
```
+ Bu durumda geri dönüş değeri olan _future_ nesnesinin _wait()_ ya da _get()_ fonksiyonlarından biri çağrıldığında _func_ senkron olarak çağrılacak.


```
int foo();
std::future<int> result = async(std::launch::async, foo);
```

#### _std::async_ işlevinin birinci parametresine _launch policy_ olarak _std::launch::async_ geçilirse
- fonksiyonu asenkron olarak çalıştırmaya zorluyoruz. Asenkron çalıştırma mümkün değil ise _std::system_error sınıfı_ türünden _exception throw_ edecek.
- fonksiyonu geri dönüş değerini _(std::future<int>)_ bir nesneye atamaz isek çağrıyı yapan _thread_ _bloke_ olacak ve _foo_ işlevinin çalışması beklenecek. Bu durumda çağrının senkron yapılmasıyla arada bir fark kalmayacak.


#### _std::async_ tarafından döndürülen _std::future_ nesnesine iki nedenle ihtiyaç duyuyoruz

_sdt::async_'e gönderilen _callable_'ın gelecekteki sonucuna _(outcome)_ bu future nesnesi yoluyla ulaşabileceğiz. Bu sonuç _(outcome)_
+ ya bir geri dönüş değeri _(return value)_
+ ya da bir _exception_ olacak

_async_'e gönderilen fonksiyonun geri dönüş türü örneğin _int_ ise _async_'in geriş dönüş değeri _std::future<int>_ olacak.
Eğer _task_ _void_ bir fonksiyon ise yani geri dönüş değeri yok ise _async_'in geri dönüş değeri _std::future<void>_ olacak.

Gönderilen _callable_'ın er geç çağrılması gerekecek. Eğer fonksiyonun çalıştırılması henüz başlatılmadıysa fonksiyonun çalışmaya başlatılması için bu _std::future_ nesnesine ihtiyacımız olacak. Yani fonksiyonun geri dönüş değerini kullanmayacak olsak da _async_'in geri dönüş değeri olan _future_ nesnesi bize gerekecek.


#### bazı notlar
+ _std::async_ işlevine gönderilen _callable_'ın geri dönüş değeri yoksa bu durumda _std::async_ fonksiyonunun geri dönüş değeri _std::future<void>_ türüdür.
+ _std::async_ işlevine gönderilen _callable_ çalıştırıldığında bir _exception_ gönderirse bu _exception_ yakalanabilir.
+ _std::async_ ile paralel çalıştırma sağlamamız senkronizasyon 
	
```
#include <future>

int foo();
int bar();

int main()
{
	auto result_foo(std::async(foo));
	int result_bar = bar();
	int result = result_foo.get() + result_bar;
	
	/*
	Burada result_foo.get() çağrısı ile 3 ayrı durum oluşabilir:
	1. eğer foo işlevi async tarafından ayrı bir thread ile koşturulmaya başlatılmış 
	ve fonksiyonun kodunun çalışması bitmiş ise sonucu hemen elde etmiş oluruz.

	2. eğer foo işlevi ayrı bir thread ile başlatılmış ancak fonksiyonun kodunun çalışması 
	henüz sonuçlanmamış ise get ile onu çağıran thread foo fonksiyonunun çalışması bitene 
	kadar bloke olur.

	3. eğer foo işlevinin çalıştıtılması henüz başlatılmadıysa, çalışmaya başlaması zorlanır 
	fonksiyon senkron gibi çalışır ve fonksiyonun çalışması bitene kadar get'i çağıran 
        thread bloke olur.
	*/

}
```

Bu ke aşağıdaki koda bakalım:

```
#include <future>

int foo();
int bar();

int main()
{
	auto result_foo(std::async(foo));
	int result = bar() + result_foo.get();
	
	/*
		Kodu bu şekilde düzenlersek olmaz.
		result_foo.get() çağrısı ile derleyici tarafından önce
		result_foo.get() ifadeis ele alınabilir. 
		Bu durumda foo fonksiyonu senkron çalışır.
	*/

}
```
