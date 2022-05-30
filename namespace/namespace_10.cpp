#include <algorithm>
#include <iostream>


namespace Nec {
	class Myclass {
	private:
		int mx = 10;
	public:
		friend void swap(Myclass &, Myclass &);
	};

	void swap(Myclass &r1, Myclass &r2)
	{
		std::cout << "Nec::swap()\n";
		int temp{ r1.mx };
		r1.mx = r2.mx;
		r2.mx = temp;
	}
}


using namespace std;

int main()
{
	Nec::Myclass m1, m2;
	
	std::swap(m1, m2);
	swap(m1, m2);
}
