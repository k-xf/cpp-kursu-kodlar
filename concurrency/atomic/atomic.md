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

- std::atomic_flag provides flag with basic atomic operations
- flag can be in one of two states: set (i.e., true) or clear (i.e., false)
- two operations for flag:
	- test and set: set state to true and query previous state
	- clear: set state to false
- default constructor initializes flag to unspecified state
- not movable and not copyable
- implementation-defined macro ATOMIC_FLAG_INIT can be used to set flag to clear state in (static or automatic) initialization using statement of the form 
	std::atomic_flag f = ATOMIC_FLAG_INIT; 
- guaranteed to be lock free
- intended to be used as building block for higher-level synchronization primitives, such as spinlock mutex

