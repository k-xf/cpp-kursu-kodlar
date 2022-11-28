template <int *p>
class Nec {};

int main()
{
	int x = 10;
	Nec<&x> nec; //gecersiz
}
