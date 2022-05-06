/*
	mutex::try_lock ornek kod
	mutex sınıflarının try_lock fonksiyonları
	mutex'i edinemezse ilgili thread'i bloke etmiyor. 
	fonksiyon bu durumda false değer dönüyor.
	böylece kilidi edinemediğinde / kilidi edinene kadar
	başka işlemler yapabiliyoruz.
*/

#include <iostream>
#include <thread>
#include <mutex>

int counter{};					// atomik olmayan paylaşılan değişken
std::mutex counter_mtx;			// counter değişkenine erişim sağlayacak mutex

void try_increase()
{
	for (int i = 0; i < 100'000; ++i) {
		if (counter_mtx.try_lock()) {   //sadece mutex edinilirse counter arttırılacak
			++counter;
			counter_mtx.unlock();
		}
	}
}

int main()
{
	std::thread ar_t[10];

	for (int i = 0; i < 10; ++i)
		ar_t[i] = std::thread(try_increase);

	for (auto& t : ar_t)
		t.join();

	std::cout << counter << " kez arttirma islemi yapilabildi.\n";
}
