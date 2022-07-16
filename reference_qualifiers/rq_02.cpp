class Nec {
public:
	void foo()&;
	void foo() const; // gecersiz
	//reference qualified fonksiyon reference qualified olmayan fonksiyon ile yüklenemez.
};
