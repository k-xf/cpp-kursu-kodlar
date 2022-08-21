C++ dilinde
+ _"default function declaration" (implicit function declarations)" yok. Tüm isimler _(identifiers)_ bildirilmeli
+ _"implicit int"_ _(örtülü int)_ kuralı geçerli değil. 
+ _const_ nesnelere ilk değer vermek zorunlu.
+ global const nesneler iç bağlantıda _(internal linkage)_
+ ilk değerini sabit ifadesi _(constant expression)_ ile almış _const_ nesnelerin oluşturduğu ifadeler sabir ifadesi olarak ele alınıyor.
+ _const T*_ türünden _T*_ türüne örtülü dönüşüm yok.
+ _T_ ve _U_ farklı türler olmak üzere _T*_ türünden _U*_ türüne örtülü dönüşüm yok. (istisnalar ileride)
+ aritmetik türler ile adres türleri arasında otomatik dönüşüm yok.
+ _T_ void olmayan bir tür olmak üzere _void*_ türünden _T*_ türüne örtülü dönüşüm yok.
+ _structure, union, enum, class (user defined types)_ etiketleri (tags) doğrudan türü niteleyen isimler olarak kullanılabiliyor.
+ programcı tarafından oluşturulan türlerin (user defined types) bir öğeye sahip olması gerekmiyor. _(empty classes)_
+ Fonksiyon tanımlarında fonksiyon parametrelerine isim vermek zorunlu değil.
+  



