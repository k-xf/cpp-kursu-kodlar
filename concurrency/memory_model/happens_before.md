Bir programın çalışma zamanında nasıl davranacağını kestirebilmemiz için şunları bilebilmemiz gerekir:
- programdaki (farklı _thread_'ler tarafından gerçekleştirilebilecek) işlemlerin _(operasyonların)_ hangi sırayla yürütüleceği _(ordering)_
- programdaki bir işlemin/işlemlerin sonuçlarının (başka _thread_'ler tarafından yürütülebilecek) diğer bir işlem/işlemler yapılmadan görülür olup olmadığı _(visibility)_

Tek bir _thread_'in söz konusu olduğu programlarda yukarıdaki soruların cevabı sezgisel olarak verilebilir.
Birden fazla _thread_'in söz konusu olduğu programlarda ise bu durum çok daha karmaşıktır.

#### happens-before ilişkisi

_A_ ve _B_ iki operasyon olsun. Bu operasyonlar aynı _thread_'de gerçekleştirilen operasyonlar olabildiği gibi farklı _thread_'lerde gerçekleştirilen operasyonlar da olabilir. Eğer _A_ operasyonunun etkileri _B_ operasyonunu yürütecek _thread_'de _B_ operasyonu yürütüdüğünde görülür durumda ise

**A happens before B** <br>

garantisi söz konusudur.

**_happens-before_ ilişkisi "zamansal olarak daha önce gerçekleşme" ilişkisine göre çok daha güçlü bir durumdur.**

Eğer _A_ operasyonu _B_ operasyonuna göre zamansal açıdan daha önce gerçekleştiriliyor ise bu _A_'nın etkilerinin _B_'yi yürütecek _thread_'de _B_ yürütülmeden önce görülür olma garantisi değildir. _caching_, _store buffer_ vs gibi mekanizmalar operasyonun etkilerinin diğer _thread_'lerde görülmesini geciktirebilir.

#### sequenced before ilişkisi
_sequenced-before_ ilişkisi aynı _thread_'deki işlemlere ilişkindir.

- _Sequenced-before_ ilişkisi geçişkendir _(transitive)_ 
A _sequenced before_ B  doğru ise
B _sequenced before_ C  doğru ise
A _sequenced before_ C  doğrudur.

```
x = 1; 		// A
y = 2; 		// B
z = x + 1;	// C
```

Aşağıdaki kodu ele alalım:<br>

```
y = a * x + b; // (y = ((a * x) + b);
```
Bu ifadede 3 işlem var: çarpma toplama ve atama. Burada<br>
çarpma işlemi  _sequenced before_ toplama işlemi <br>
toplama işlemi _sequenced before_ atama işlemi <br>
dolayısıyla <br>
atama işlemi _sequenced before_ toplama işlemi <br>

Eğer bir _thread_ için <br>
A _sequenced before_ B doğru ise <br>
A _happens before_ B doğrudur.<br>

Bu şu anlama geliyor:<br>
_sequenced-before_ ilişkisi aynı zamanda _thread_ içindeki _(intra-thread)_ happens before ilişkisine karşılık geliyor.<br>

- _happens-before_ ilişkisi zamana bağlı değildir, görünürlüğe _(visibility)_ bağlıdır.
- _A happens before B_ ise, bu A'nın B'de önce yapılması anlamına gelmez (böyle bir garanti yoktur).
- A B'den önce yapılmış ise _A happens-before B_ olmak değildir.
- happens-before ilişkisi _acquire-release_ semantiği ile gerçekleştirilebilir. (Daha sonra ele alacağım)

**Happens-Before Does Not Imply Happening Before!**

Aşağıdaki koda bakalım:
```
#include <cstdio>

int is_ready = 0;
int answer = 0;

void producer()
{
    answer = 42;                        // (1)
    is_ready = 1;                      // (2)
}

void consumer()
{
    if (is_ready)                      // (3) <-- Burada okunan değerin 1 olduğunu düşünelim
        printf("%d\n", answer); // (4)
}
```
