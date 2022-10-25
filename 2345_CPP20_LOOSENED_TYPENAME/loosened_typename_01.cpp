
template<typename T>
T::Neco func(); // Invalid at C++17. Valid at C++20


template<typename T>
void func(T::Neco); // Invalid C++17/C++20


template<typename T>
void func(typename T::Neco); // Valid C++17/C++20


template <typename T>
struct PointerTrait {
	using Ptr = void*;
};


template<typename T>
struct Nec {
	using Ptr = PointerTrait<T>::Ptr; //Invalid at C++17.Valid in C++20.

	T::Neco foo(T::Ali x) //C++20. Valid
	{

	}
};
