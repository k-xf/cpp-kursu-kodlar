#### condition variable

- _condition variable_ bir başka _thread_'in tetikleyeceği bir _event_'i beklememenin temel mekanizmasıdır. 
- Birden fazla _thread_'in kullanıldığı programlarda çoğu zaman bir _thread_'in belirli bir _event_ oluşuncaya kadar beklemesi gerekir (giriş çıkış işleminin tamamlanması ya da bir verinin hazırlanması gibi)
- Bir _thread_'in bir eventin gerçekleşip gerçekleşmediğini sorgulaması işlemci zamanının boşa harcanmasına dolayısıyla verimin düşmesine neden olabilir.
- Böyle durumlarda bekleyen thread'in bloke olması ve ilgili event gerçekleştikten sonra tekrar çalışmaya başlaması genellikle daha iyidir.
- Bir _condition variable_, belirli bir koşul gerçekleşinceye kadar bir _thread_'in bloke olarak beklemesini sağlayan bir senkronizasyon yapısıdır.
+ Bir _condition variable_ bir _event_ ile ilişkilendirilir.
+ Bir _event_'i beklemek isteyen bir _thread_ _condition variable_'ın _wait_ fonksiyonunu çağırır. 
+ Bir _thread_ bir _event_'in gerçekleşmiş olduğunu bir ya da birden fazla _thread_'e bildirmek için _condition variable_'ın _notify_one_ ya da _notify_all_ fonksiyonlarından birini çağırır. 

