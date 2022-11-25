template <typename D> 
class B {
public:
	friend D operator+(const D& lhs, const D& rhs) 
	{
		D res(lhs);
		res += rhs; // Convert += to +
		return res;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const D& d) 
	{
		d.print(out);
		return out;
	}
};

template <typename T> 
class C : public B<C<T>> {
	T x_;
public:
	C(T x) : x_(x) {}
	C operator+=(const C& incr) 
	{
		x_ += incr.x_;
		return *this;
	}
	
	void print(std::ostream& out) const 
	{
		out << x_;
	}
};
