#include <stdexcept>
#include <cmath>
#include <vector>
#include <future>
#include <numeric>
#include <iostream>


double square_root(double x)
{
	if (x < 0.)
		throw std::domain_error("square root of a negative integer!!!");

	return std::sqrt(x);
}

int main()
{
	std::vector<double> dvec(10);

	std::iota(dvec.begin(), dvec.end(), 20);

	dvec.back() = -1;

	std::vector<std::future<double>> ftr_vec;
	ftr_vec.reserve(dvec.size());

	for (auto dval : dvec) {
		ftr_vec.push_back(std::async(square_root, dval));
	}

	for (auto& x : ftr_vec) {
		try {
			std::cout << x.get() << "\n";
		}
		catch (const std::domain_error& d_ex) {
			std::cout << "hata yakalandi : " << d_ex.what() << "\n";
		}
	}
}
