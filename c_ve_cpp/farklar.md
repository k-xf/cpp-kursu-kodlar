C++ dilinde
+ _"default function declaration" (implicit function declarations)"_ yok. Tüm isimler _(identifiers)_ bildirilmeli.
+ _"implicit int"_ _(örtülü int)_ kuralı geçerli değil. 
+ string literalleri _const char_ diziler. (C'de string literalleri char diziler)
+ karakter sabitlerinin _(character literals)_ türü _int_ değil _char_.
+ _const_ nesnelere ilk değer vermek zorunlu.
+ global _const_ nesneler iç bağlantıda _(internal linkage)_
+ ilk değerini sabit ifadesi _(constant expression)_ ile almış _const_ nesnelerin oluşturduğu ifadeler sabit ifadesi olarak ele alınıyor.
+ _const T*_ türünden _T*_ türüne örtülü dönüşüm yok.
+ char* türünden değişkenlere string literalleri ile ilk değer veremeyiz. char* türünden değişkenlere string literallerini atayamayız.
+ _T_ ve _U_ farklı türler olmak üzere _T*_ türünden _U*_ türüne örtülü dönüşüm yok. (istisnalar ileride)
+ aritmetik türler ile adres türleri arasında otomatik dönüşüm yok.
+ _T_ void olmayan bir tür olmak üzere _void*_ türünden _T*_ türüne örtülü dönüşüm yok.
+ _structure, union, enum, class (user defined types)_ etiketleri _(tags)_ doğrudan türü niteleyen isimler olarak kullanılabiliyor.
+ programcı tarafından oluşturulan türlerin _(user defined types)_ bir öğeye sahip olması gerekmiyor. _(empty classes)_
+ Fonksiyon tanımlarında fonksiyon parametrelerine isim vermek zorunlu değil.
+ ```char str[4] = "mert"``` dizi boyutu ile ilk değer veren yazıdaki karater sayısı eşit ise tanım _(definition)_ geçerli değil.
+ aritmetik türlerden _enum_ türlerine örtülü dönüşüm yok.
+ farklı _enum_ türleri arasında örtülü dönüşüm yok.




