template <typename T>
struct TypeIdentity {
	using type = T;
};

template <bool condition, typename T, typename U>
struct conditional : TypeIdentity<T> {};

template <typename T, typename U>
struct conditional<false, T, U> : TypeIdentity<U> {};
