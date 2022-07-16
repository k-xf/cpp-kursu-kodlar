class [[nodiscard]] Nec {
	//...
};


Nec foo();
Nec& func();

int main()
{
	foo(); //derleyici uyarisi
	func(); //derleyici uyarisi yok
}
