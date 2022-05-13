#### condition variable

- _condition variable_ bir başka _thread_'in tetikleyeceği bir _event_'i beklememenin temel mekanizmasıdır. 
- Birden fazla _thread_'in kullanıldığı programlarda çoğu zaman bir _thread_'in belirli bir _event_ oluşuncaya kadar beklemesi gerekir (giriş çıkış işleminin tamamlanması ya da bir verinin hazırlanması gibi)
- Bir _thread_'in bir eventin gerçekleşip gerçekleşmediğini sorgulaması işlemci zamanının boşa harcanmasına dolayısıyla verimin düşmesine neden olabilir.
- Böyle durumlarda bekleyen thread'in bloke olması ve ilgili event gerçekleştikten sonra tekrar çalışmaya başlaması genellikle daha iyidir.
- Bir _condition variable_, belirli bir koşul gerçekleşinceye kadar bir _thread_'in bloke olarak beklemesini sağlayan bir senkronizasyon yapısıdır.
+ Bir _condition variable_ bir event ile ilişkilendirilir.

 
