//bu işlev cagrilmadigi icin derleyici uyari verebilir
static void func()
{
	//...
}

[[maybe_unused]] static void foo()
{

} // Bu fonksiyon cagrilmaz ise derleyici uyari vermeyecek


int main()
{
	int x = 42; //bu degisken kullanilmadigi icin derleyici uyari verebilir
	[[maybe_unused]] int y = 42; //bu degisken kullanilmadigi icin derleyici uyari vermeyecek
}
