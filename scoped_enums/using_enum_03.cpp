enum class Days{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

void func()
{
	using Days::Sunday;

	auto d1 = Sunday;
	//auto d2 = Monday; //invalid
	//...
}
