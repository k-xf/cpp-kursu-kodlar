
_std::unique_lock_ <mutex> başlık dosyasında tanımlanan bir sınıf şablonu.
```
template <class Mutex>
class unique_lock;
```


_std::unique_lock_ genel amaçlı bir mutex sarmalayıcısı. Aşağıdaki olanakları sağlıyor:

+ **deferred locking** (sınıfın kurucu işlevi ile kilidi edinebildiğimiz gibi daha sonra nesnenin _lock_ işlevini de çağırabiliyoruz.)
+ **time-constrained attempts at locking**
+ **recursive locking**
+ **kilit mülkiyetinin transferi**
+ **condition variables ile kullanılma olanağı**

_std::unique_lock_ nesneleri kopyalanamıyor ancak taşınabiliyor.
  
 std::lock_guard ile aynı arayüze sahip ama daha fazla olanak sağlıyor. Kilitlemenin ne zaman ve nasıl olacağını belirleyebiliyoruz
  
Bu sınıfın temel avantajı şu:
_std::unique_lock_ nesnesinin _destructor_'ı çağrıldığında kilit edinilmiş durumda ise kilidi serbest bırakır, kilit edinilmiş durumda değil ise _destructor_ bir şey yapmaz.
 
sınıfın _constructor_'una argüman olarak _try_to_lock_ geçersek kurucu işlev kilidi edinmeye çalışır ama _thread_'i bloke etmez.

```
std::mutex mtx;

void func()
{
    std::unique_lock<std::mutex> guard(mutex, std::try_to_lock);
    if (guard) { //kilit edinilmis ise

    }
}

```
  
_mutex_ türü olarak _std::time_mutex_ kullanarak belirli süre bir kilidi edinmeye çalışmasını sağlayabiliyoruz:

```
std::mutex mtx;

void func()
{
    std::unique_lock<std::mutex> guard(mtx, std::try_to_lock);
    if (guard) { //kilit edinilmis ise

    }
}
```

_std::time_mutex_ kullanarak _constructor_'a bir durayion geçebiliriz:

```
std::unique_lock<std::timed_mutex> lock(mutex, std::chrono::seconds(1));
```
