+ _std::map_ sınıfının bu üye fonksiyonu C++17 standartları ile eklendi. 
+ _std::map_ sınıfının operator[] fonksiyonuna bir alternatif oluşturuyor.
+ _operator[]_ fonksiyonu _mapped_type_'ın default constructible olmasını şart koşuyor. Ama _insert_or_assign_ için bu koşul gerekmiyor.
+ _operator[]_ fonksiyonu insert işleminin yapılıp yapılmadığı konusunda bilgi vermiyor. Ancak insert_or_assign geri dönüş değeri ile bu bilgiyi iletiyor.
