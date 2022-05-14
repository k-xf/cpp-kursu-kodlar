#### condition variable

- _condition variable_ bir başka _thread_'in tetikleyeceği bir _event_'i beklemenin temel mekanizmasıdır. _(Synchronization primitive)_
- Birden fazla _thread_'in kullanıldığı programlarda çoğu zaman bir _thread_'in belirli bir _event_ oluşuncaya kadar başka bir _thread_'i beklemesi gerekir (giriş çıkış işleminin tamamlanması ya da bir verinin hazırlanması gibi)
- Bir _thread_'in bir _event_'in gerçekleşip gerçekleşmediğini sürekli olarak sorgulaması, işlemci zamanının boşa harcanmasına, dolayısıyla verimin düşmesine neden olabilir.
- Böyle durumlarda bekleyen _thread_'in bloke olması ve ilgili _event_ gerçekleştikten sonra _thread_'in tekrar çalışmaya başlaması genellikle daha iyidir.
- Bir _condition variable_, belirli bir koşul _(condition)_ gerçekleşinceye kadar bir _thread_'in (bloke olarak) beklemesini sağlayan bir senkronizasyon yapısıdır.
+ Bir _condition variable_ bir _event_ ile ilişkilendirilir.
+ Bir _event_'i beklemek isteyen bir _thread_, _condition variable_'ın _wait_ fonksiyonlarından birini çağırır. _(wait, wait\_for, wait\_until)_
+ Bir _thread_ _(producer)_ bir _event_'in gerçekleşmiş olduğunu bir ya da birden fazla _thread_'e _(consumers)_ bildirmek için _condition variable_'ın _notify_one_ ya da _notify_all_ fonksiyonlarından birini çağırır. 
+ Bildirimi alan _thread_ çalışmaya devam ettiğinde istenen koşulun sağlanmış olma garantisi yoktur. 
Başka bir _thread_ koşulun değişmesini sağlamış olabilir ya da _"spurious wakeup"_ denilen durum oluşmuş olabilir. (Bekleyen bir _thread_'in aslında diğer taraftan bir bildirim almadan uyanmasına "spurious wake" denir.)

Bu nedenle uyanan _thread_'in koşulun sağlanmış olup olmadığını tekrar kontrol etmesi gerekir.
- _condition_variable_ olarak _std::condition_variable_ sınıfı türünden bir nesne kullanılır.
- _condition_variable_ sınıfı _\<condition_variable\>_ başlık dosyasında tanımlanmıştır. _std::condition_variable_ nesneleri kopyalanamaz ve taşınamaz _(not copyable - not moveable)_.
- sınıfın _wait, wait_for_ ya da _wait_until_ üye fonksiyonları ile bekleyecek _thread_ bloke edilir koşulun sağlanması beklenir. 
- sınıfın _notify_one_ ve _notify_all_ üye fonksiyonları ile bekleyen _thread_'lere koşulun oluştuğu bildirilir _(signal)_.
- uyanan _thread_'in koşulu tekrar sınaması gerekir, çünkü
  - _spurious wakeup_ oluşabilir.
  - sinyalin alınması ve _mutex_'in edinilmesi zaman aralığı içinde başka bir _thread_ koşulu değiştirmiş olabilir.
- _wait, wait_for_ ve _wait_until_ fonksiyonları _mutex_'i atomik olarak edinirler ve ilgili _thread_'i bloke ederler.
- _notify_one_ ve _notify_all_ fonksiyonları atomiktir.

Tipik işlem akışı şöyle gerçekleştirilir:
Evet'i gerçekleştirecek ve diğer _thread_'e bildirimde bulunacak _thread_
- Tipik olarak _std::lock_guard_ ya da _std::lock_guard_ kullanarak bir _mutex_'i edinir. <br>
- Kilit edinilmiş durumdayken (paylaşılan) koşul değişkenini değiştirir. Yapılan değişikliğin bekleyen _thread_(ler)e doğru bir şekilde bildirilebilmesi için, paylaşılan değişken atomik olsa dahi değişikliğin kilit edinilmiş durumda yapılması gerekir.<br>
- Bu amaçla tanımlanmış olan _std::condition_variable_ nesnesinin _notify_one_ ya da _notify_all_ fonksiyonlarından birini çağırır. Bu fonksiyonlar çağrıldığında kilitin edinilmiş durumda olması gerekmez. Eğer bu fonksiyonlar kilit edinilmiş durumda çağrılırsa bildirim alan _thread_'ler kilidi edinemezler ve tekrar bloke olurlar.
<br>

Bekleyen bir _thread_, önce _std::unique\_lock_ kullanarak (aynı) _mutex_'i edinir. Daha sonra aşağıdaki iki seçenekten birini uygular:<br>
- Birinci seçenek
  - Değişikliği zaten yapılmış ve bildirimin de gerçekleşmiş olabileceği ihtimaline karşı önce kuşulu test eder.
  - wait, wait\_for, ya da wait\_until fonksiyonlarından birini çağırır. Çağrılan _wait_ fonksiyonu edinilmiş _mutex_'i otomatik olarak serbest bırakır ve _thread_'in çalışmasını durdurur.
  - _condition\_variable_ nesnesinin _notify_ fonksiyonu çağrıldığında (ya da bekleme süresi dolduğunda) ya da bir _"spurious wakeup"_ oluştuğunda, _thread_ uyanır ve _mutex_ yeniden edinilir.
 - Uyanan ve kilidi edinen _thread_'in koşulun gerçekleşip gerçekleşmediğini kontrol etmesi ve eğer bir _spurious wakeup_ söz konusu ise tekrar bekleme durumuna geçmesi gerekir.

- İkinci seçenek olarak bekleyen _thread_
  - bu işlemlerin hepsini sarmalayan _wait_ fonksiyonlarının bir _predicate_ alan _overload_'larından birini çağırır. 

_std::condition\_variable_ sınıfı yalnızca _std::unique\_lock<std::mutex>_ ile kullanılabilir. Bu şekilde kullanım zorunluluğu bazı platformlarda en yüksek verimle çalışmasını sağlar. _std::condition\_variable_any_ sınıfı ise _BasicLockable_ niteliğini sağlayan herhangi bir nesneyle _(örneğin std::shared\_lock)_ çalışabilmesini sağlar.<br>
_std::condition\_variable_ sınıfının _wait, wait\_for, wait\_until, notify_one ve notify\_all_ üye fonksiyonları birden fazla _thread_ tarafından eş zamanlı çağrılabilir.

_std::condition_variable_ sınıfının _wait_ üye fonksiyonu, _(busy wait)_ için bir optimizasyon olarak görülebilir. _wait_ fonksiyonunun (ideal olmasa da) gerçekleştirimi şöyle olabilir:

```
template<typename Pred>
void wait(std::unique_lock<std::mutex>& lk, Predicate pred) 
{
	while(!pred()) {
		lk.unlock();
		lk.lock();
	}
}
```
