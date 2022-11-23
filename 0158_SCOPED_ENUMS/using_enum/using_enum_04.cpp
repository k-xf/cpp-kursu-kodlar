enum class Days{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

void func()
{
	using enum Days;

	auto d1 = Sunday;
	auto d2 = Monday; 
	auto d3 = Friday; 
	//...
}
