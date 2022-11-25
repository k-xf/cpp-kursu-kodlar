#include <vector>

template <typename T>
using veciter = typename std::vector<T>::iterator;

int main()
{
	veciter<int> iter;
	//...
}
