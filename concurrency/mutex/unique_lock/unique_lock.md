
_std::unique_lock_ <mutex> başlık dosyasında tanımlanan bir sınıf şablonu.
```
template <class Mutex>
class unique_lock;
```


_std::unique_lock_ genel amaçlı bir mutex sarmalayıcısı. mutex'in edinilmesi için farklı stratejiler sunuyor: 

+ **deferred locking** (sınıfın kurucu işlevi ile kilidi edinebildiğimiz gibi daha sonra nesnenin _lock_ işlevini de çağırabiliyoruz.)
+ **belirli süreyle sınırlandırılmış kilitleme girişimi olanağı**
+ **birden fazla kez kilitleme**
+ **kilit mülkiyetinin transferi**
+ **condition variables ile kullanılma olanağı**

Ayrıca
+ _std::unique_lock_ nesneleri kopyalanamıyor ancak taşınabiliyor. _std::lock_guard_ sınıf nesnelerinin taşınamadığını hatırlayalım.
+ _std::lock_guard_ ile aynı arayüze sahip ama daha fazla olanak sağlıyor. Kilitlemenin ne zaman ve nasıl olacağını belirleyebiliyoruz.
+ Bu sınıfın temel avantajı şu:
_std::unique_lock_ nesnesinin _destructor_'ı çağrıldığında kilit edinilmiş durumda ise kilidi serbest bırakır, kilit edinilmiş durumda değil ise _destructor_ bir şey yapmaz.
 
+ sınıfın kurucu işlevine argüman olarak _try_to_lock_ geçersek kurucu işlev kilidi edinmeye çalışır ama _thread_'i bloke etmez.

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

_std::time_mutex_ kullanarak kurucu işleve bir _std::duration_ geçebiliriz:

```
std::unique_lock<std::timed_mutex> lock(mutex, std::chrono::seconds(1));
```

+ sınıfın kurucu işlevine argüman olarak _std::defer_lock_ geçilirse _mutex_'i edinmez. daha sonra sınıfın _lock_ fonksiyonlarından birini çağırmamız gerekiyor.
+ sınıfın kurucu işlevine _std::adopt_lock_ geçilirse ilgili _thread_'in zaten bu _mutex_'i edindiği varsayılır.
+ edinilen _mutex_'in sahipliğini başka bir nesneye aktarabiliyoruz.
