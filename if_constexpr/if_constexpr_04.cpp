constexpr auto func()
{
	if constexpr (sizeof(int) > 4u) {
		return 1;
	}
	else {
		return 0.5;
	}
}

int main()
{
	constexpr auto val = func();
}
