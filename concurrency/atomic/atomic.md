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

