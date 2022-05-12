#include <mutex>
#include <condition_variable>
#include <iostream>
#include <future>


int data{};
bool ready_flag;
std::mutex ready_mutex;
std::condition_variable cond_var;


// bu fonksiyon diğer thread(ler) için veriyi hazırlayacak. 
// (onların işlerini görmesi için gerekli işlemleri yapacak)
// veriyi hazırlayınca diğer thread(ler)e  haber verecek.

void producer()
{
	std::cout << "producer is producing data" << std::endl;
	{
		std::lock_guard<std::mutex> guard(ready_mutex);
		data = 4567;
		ready_flag = true;
	} // burada kilit açılıyor
	cond_var.notify_one(); //burada diger thread(ler)e haber veriliyor
}

//bu fonksiyon producer tarafından üretilen veriyi kullanacak
// iş(ler)ini yapabilmesi için diğer threadin bazı işlemleri yapmış olması gerekiyor

void consumer()
{
	//producer veriyi üretene kadar bekliyor
	{
		std::unique_lock<std::mutex> ul(ready_mutex);
		cond_var.wait(ul, [] { return ready_flag; }); //kendisine haber verilmesini bekliyor.
	} // burada kilit hazırlanıyor
	// burada artık producer işini yapmış durumda
	std::cout << "data = " << data << std::endl;
}

int main()
{
	std::thread t1{ producer };
	std::thread t2{ consumer };
	t1.join();
	t2.join();
}
