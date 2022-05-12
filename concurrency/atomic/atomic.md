#### atomic

- _Thread_'ler arasında veriyi paylaşırken _"data race"_ oluşmaması için genellikle bir senkronizasyon mekanizması gereklidir. (örneğin _mutex_ kullanarak senkronizasyonu sağlamak).
- Veriye senkronize edilmiş erişim sağlamanın başka bir yolu da atomik türleri kullanmaktır.
- Bölünemeyecek bir işleme "atomik işlem" denir. Atomik bir işlem arasına başka bir işlem giremez. Örneğin arttırma işlemi atomik ise bu işleme tabi tutulan bir değişken diğer _thread_'ler tarafından ya işlemden önceki ya da işlemden sonraki değeri ile görülebilir.
 İşlemcilerin çoğunda atomik bellek işlemleri özel makine komutları ile gerçekleştirilir.
- atomik bellek işlemleri _"torn read"_ ya da _"torn write"_ durumu oluşturmazlar.
- C++ standart kütüphanesi atomik bellek işlemleri için aşağıdaki atomik türleri sunmaktadır:
    - _std::atomic_flag_
    - _std::atomic_
- Bu türler donanımın sağladığı atomik operasyonlar için uniform bir arayüz sunarlar.

An atomic type provides guarantees regarding:
	- atomicity; and
	- ordering.
- An ordering guarantee specifies the manner in which memory operations can become visible to threads.
- Several memory ordering schemes are supported by atomic types.
- The default memory order is sequentially consistent (std::memory_order_seq_cst).
- Initially, only this default will be considered.

- std::atomic_flag türü sadece temel işlemler sunar.
- Bu türden bir değişken (flag) yalnızca iki durumda olabilir. Ya _set_ edilmiş durumda (true) ya da _clear_ edilmiş durumda (yani _false_)
- bu tür 2 operasyon sunar:
	- _test_and_set_: state'i true yaparken set işleminden önceki değeri sorgular _(get eder)_. 
	- clear: set state to false
- varsayılan kurucu işlev (default ctor) nesneyi 
- kopyalanamayan ve taşınamayan bir türdür.
- implementation-defined macro ATOMIC_FLAG_INIT can be used to set flag to clear state in (static or automatic) initialization using statement of the form 
	std::atomic_flag f = ATOMIC_FLAG_INIT; 
- bir kilit mekanizmasının kullanılmadığı garanti edilmektedir.
- intended to be used as building block for higher-level synchronization primitives, such as spinlock mutex

