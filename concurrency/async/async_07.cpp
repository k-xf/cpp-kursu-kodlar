#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <numeric>
#include <iomanip>

static constexpr size_t size = 100'000'000;

long long get_dot_product(const std::vector<int>&left, const std::vector<int>&right)
{
	auto vsize= left.size();
	auto f = [&](const int* ps, const int* pe, const int* pd) 
	{
		return std::inner_product(ps, pe, pd, 0LL);
	};

	auto future1 = std::async(f, &left[0], &left[vsize/ 4], &right[0]);
	auto future2 = std::async(f, &left[vsize/ 4], &left[vsize/ 2], &right[vsize/ 4]);
	auto future3 = std::async(f, &left[vsize/ 2], &left[vsize* 3 / 4], &right[vsize/ 2]);
	auto future4 = std::async(f, &left[vsize* 3 / 4], &left[vsize], &right[vsize * 3 / 4]);

	return future1.get() + future2.get() + future3.get() + future4.get();
}


int main() 
{
	std::cout << std::fixed << std::setprecision(2);
	std::mt19937 eng(std::random_device{}());
	std::uniform_int_distribution dist{ 0, 20 };
	auto f = [&] {return dist(eng); };

	std::vector<int> left(size), right(size);
	std::generate_n(left.begin(), size, f);
	std::generate_n(right.begin(), size, f);

	using msec = std::chrono::duration<double, std::milli>;

	auto tp_start = std::chrono::steady_clock::now();
	auto val = get_dot_product(left, right);
	//auto val = std::inner_product(left.begin(), left.end(), right.begin(), 0LL);
	auto tp_end = std::chrono::steady_clock::now();
	std::cout << "toplam sure : " << msec(tp_end - tp_start).count() << '\n';
	std::cout << "val = " << val << "\n";
}
