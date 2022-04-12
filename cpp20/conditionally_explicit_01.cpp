template<typename T>
struct Nec {
	explicit(false) Nec(T); // C++20. Constructor is not explicit
	
	//explicit(true) Nec(T); // C++20. Constructor is explicit
	
	//explicit(std::is_integral_v<T>)Nec(T); // C++20. Conditionally
};


template<typename T>
struct Myclass{
	explicit(!std::is_convertible_v<T,int>)Myclass(T); // Conditionally

	//explicit(true) Myclass(T); // C++20. Constructor is explicit
	
	//explicit(false) Myclass(T); // C++20. Constructor is not explicit
	
	//explicit(std::is_convertible_v<T,int>)Myclass(T); // Conditionally
};
