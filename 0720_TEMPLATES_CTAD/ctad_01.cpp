template <typename T = double>
struct Nec {
	T val;
	Nec() : val() {}
	Nec(T val) : val(val) {}
	// ...
};

Nec nec1{ 10 }; // Nec<int>
Nec nec2;      // Nec<double>
