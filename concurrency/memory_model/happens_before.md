#### happens-before ilişkisi

_A_ ve _B_ iki operasyon olsun. Bu operasyonlar aynı _thread_'de gerçekleştirilen operasyonlar olabildiği gibi farklı _thread_'lerde gerçekleştirilen operasyonlar da olabilir.
Eğer _A_ operasyonunun etkileri _B_ operasyonunu yürütecek _thread_'de _B_ operasyonu yürütülmeden önce görülür durumda ise

**A happens before B ** <br>

garantisi söz konusudur.

_happens-before_ ilişkisi "zamansal olarak daha önce gerçekleşme" ilişkisine göre çok daha güçlü bir durumdur.

Eğer _A_ operasyonu _B_ operasyonuna göre zamansal açıdan daha önce gerçekleştiriliyor ise bu _A_'nın etkilerinin _B_'yi yürütecek _thread_'de _B_ yürütülmeden önce görülür olma garantisi değildir. _caching_, _store buffer_ vs gibi mekanizmalar operasyonun etkilerinin diğer _thread_'lerde görülmesini geciktirebilir.

Daha erken zamanda oluşma garantisi _happens-before_ ilşkisi için gerek şarttır ancak yeter şart değildir.
