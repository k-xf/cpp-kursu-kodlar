class Encloser {
	struct Nested {
		int get_sizeof_x() const
		{
			return sizeof(mx); // Gecerli (unavaluated context)
		}
		
		int get_x() const 
		{
			return mx; // //Gecersiz ortada nesne yok
		}
		
		int get_x(Encloser &enc)
		{
			//...
			return enc.mx; // Eksiden gecersizdi C++11 ile gecerli hale geldi
		}
	};
	int mx;
};
