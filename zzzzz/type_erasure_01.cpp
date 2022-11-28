#include <memory>
#include <iostream>

template <typename T>
void print(const T& t)
{
	std::cout << t << '\n';
}

class Printable {
public:
	template <typename T>
	Printable(const T &x) : mptr(std::make_unique<Model<T>>(x)) {}
	Printable(const Printable& other) : mptr{other.mptr->clone()} {}
	Printable(Printable&& other) noexcept = default;
	Printable& operator=(const Printable& other)  
	{
		return *this = Printable(other);
	}

	friend void print(const Printable& p)
	{
		p.mptr->print_impl();
	}

private:
	struct Concept {
		virtual ~Concept() = default;
		virtual void print_impl()const = 0;
		virtual std::unique_ptr<Concept> clone() const = 0;
	};

	template <typename T>
	struct Model final : Concept {
		Model(const T& x) : mx(x) {}
		void print_impl()const override
		{
			print(mx);
		}

		std::unique_ptr<Concept> clone() const override
		{
			return std::make_unique<Model>(*this);
		}


		T mx;
	};
	std::unique_ptr<Concept> mptr;
};

#include <vector>


int main()
{

	std::vector<Printable> pvec;

	pvec.emplace_back(12);
	pvec.emplace_back(3.4);
	pvec.emplace_back(87L);

	for (const auto& p : pvec)
		print(p);
}
