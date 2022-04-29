
_std::unique_lock_ <mutex> başlık dosyasında tanımlanan bir sınıf şablonu.
```
template <class Mutex>
class unique_lock;
```


_std::unique_lock_ genel amaçlı bir mutex sarmalayıcısı. Aşağıdaki olanakları sağlıyor:

+ **deferred locking** (sınıfın kurucu işlevi ile kilidi edinmek yerine daha sonra nesnenin _lock_ işlevini çağırabiliyoruz.)
+ **time-constrained attempts at locking**
+ **recursive locking**
+ **kilit mülkiyetinin transferi**
+ **condition variables ile kullanılma olanağı**

_std::unique_lock_ nesneleri kopyalanamıyor ancak taşınabiliyor.
  
 std::lock_guard ile aynı arayüze sahip ama daha fazla olanak sağlıyor. Kilitlemenin ne zaman ve nasıl olacağını belirleyebiliyoruz
  
Bu sınıfın temel avantajı şu:
std::unique_lock nesnesinin destructor'ı çağrıldığında kilit edinilmiş durumda ise kilidi serbest bırakır, kilit edinilmiş durumda değil ise destructor bir şey yapmaz.
 
