+ **race condition:** Öyle bir davranış ki bu davranıştan çıkan sonuç iki ya da ikiden fazla _thread_'in yürütülmesindeki görece sıraya göre değişebiliyor.
_race condition_ bir sorun oluşturmak zorunda değil. (_benign_ olabilir). Ancak bu terim daha çok problemli durumlar için kullanılıyor. (_invariant_'lar bozuluyor ya da tanımsız davranış oluşuyor.)
+ **data race** kötü (benign olmayan) bir _race condition_. _data race_ tanımsız davranış oluşturuyor.
+ **deadlock:** iki ya da daha fazla sayıda _thread_ ilerleme kaydedemiyor. Her ikisi de diğerinin tuttuğu kaynağı bekleyecek şekilde bloke oluyorlar.
race condition
+ **livelock:** iki ya da daha fazla _thread_ (bloke olmadan) birbirlerinin tuttuğu kaynakları beklediklerinden ilerleme kaydedemiyorlar.
+ **critical section** Birden fazla _thread_ tarafından eş zamanlı olarak erişilmemesi gereken bir kaynak içeren bir kod parçası.
