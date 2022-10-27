//[[nodiscard]] attribute C++17

struct[[nodiscard]] Neco {
	int x, y;
};

Neco func();

int main()
{
	func();  //compiler emits warning
}
