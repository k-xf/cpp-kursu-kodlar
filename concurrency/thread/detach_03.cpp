//foo işlevi içindeki yerel değişken ival'in ömrü bitmesine karşılık oluşturulan thread'in çalışması devam ediyor olabilir

#include <thread>

class Functor {
public:
	Functor(int &r) :mr(r) {}
	void operator()()
	{
		for (int i = 0; i < 100000; ++i) {
			//...
		}
	}
private:
	int& mr;
};


void foo()
{
	int ival = 0;
	Functor myfunctor(ival);
	std::thread t(myfunctor);
	t.detach();
}
