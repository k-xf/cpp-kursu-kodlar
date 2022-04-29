#include <vector>
#include <thread>
#include <mutex>
#include <cassert>
#include <memory>

std::unique_ptr<int> uptr;
std::once_flag init_flag;

void init() 
{
	uptr = std::make_unique<int>(42);
}

const int& get_value()
{
	std::call_once(init_flag, init);
	return *uptr;
}


void do_work() 
{
	const int& v = get_value();
	assert(v == 42);
}

int main()
{
	std::vector<std::jthread> threads;
	
	for (int i = 0; i < 4; ++i) {
		threads.emplace_back(do_work);
	}
}
