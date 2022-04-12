struct Nec {
	int a, b;
	
	struct Nested {
		int x;
	}c;
};

int main()
{
	using namespace std;

	auto p = make_unique<Nec>(1, 2, Nec::Nested{ 3 }); //Valid at C++20. Invalid at C++17
	
	vector<Nec> nvec;
	nvec.emplace_back(1, 2, Nec::Nested{ 3 });  //Valid at C++20. Invalid at C++17
}


//-----------------------------------------------------------------------------------------------------------------
