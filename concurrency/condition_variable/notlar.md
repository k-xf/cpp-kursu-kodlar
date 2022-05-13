#### condition variable

- _condition variable_ bir başka _thread_'in tetikleyeceği bir _event_'i beklememenin temel mekanizmasıdır. 
- Birden fazla _thread_'in kullanıldığı programlarda çoğu zaman bir _thread_'in belirli bir _event_ oluşuncaya kadar beklemesi gerekir (giriş çıkış işleminin tamamlanması ya da bir verinin hazırlanması gibi)
- Bir _thread_'in bir _event_'in gerçekleşip gerçekleşmediğini sorgulaması işlemci zamanının boşa harcanmasına dolayısıyla verimin düşmesine neden olabilir.
- Böyle durumlarda bekleyen _thread_'in bloke olması ve ilgili event gerçekleştikten sonra tekrar çalışmaya başlaması genellikle daha iyidir.
- Bir _condition variable_, belirli bir koşul gerçekleşinceye kadar bir _thread_'in bloke olarak beklemesini sağlayan bir senkronizasyon yapısıdır.
+ Bir _condition variable_ bir _event_ ile ilişkilendirilir.
+ Bir _event_'i beklemek isteyen bir _thread_ _condition variable_'ın _wait_ fonksiyonunu çağırır. 
+ Bir _thread_ bir _event_'in gerçekleşmiş olduğunu bir ya da birden fazla _thread_'e bildirmek için _condition variable_'ın _notify_one_ ya da _notify_all_ fonksiyonlarından birini çağırır. 
+ Bildirimi alan _thread_ çalışmaya devam ettiğinde istenen koşulun sağlanmış olma garantisi yoktur. Başka bir _thread_ koşulun değişmesini sağlamış olabilir ya da _"spurious wakeup"_ denilen durum oluşmuş olabilir. Bu nedenle uyanan _thread_'in koşulun sağlanmış olup olmadığını kontrol etmesi gerekir.
- _condition_variable_ olarak _std::condition_variable_ sınıfı türünden bir nesne kullanılır.
- _std::condition_variable_ nesneleri kopyalanamaz ve taşınamaz _(not copyable - not moveable)_.
- sınıfın _wait, wait_for_ ya da _wait_until_ üye fonksiyonları ile koşulun sağlanması beklenir. 
- sınıfın _notify_one_ ve _notify_all_ üye fonksiyonları ile bekleyen _thread_'lere koşulun oluştuğu bildirilir (signal).
- uyanan _thread_'in koşulu tekrar sınaması gerekir, çünkü
  - _spurious wakeup_ oluşabilir.
  - sinyalin alınması ve _mutex_'in edinilmesi zaman aralığı içinde başka bir _thread_ koşulu değiştirmiş olabilir.
- _wait, wait_for_ ve _wait_until_ fonksiyonları _mutex_'i atomik olarak edinirler ve ilgili _thread_'i bloke ederler.
- _notify_one_ ve _notify_all_ fonksiyonları atomiktir.
