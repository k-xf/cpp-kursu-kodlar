template <const char *p>
class Nec {};

char s[] = "necati";
const char cs[] = "ergin";
int main()
{
	char str[] = "mustafa";
	//Nec<"alican"> n1; //gecersiz
	//Nec<str> n2; //gecersiz
	Nec<s> n3;
	Nec<cs> n4;
}
