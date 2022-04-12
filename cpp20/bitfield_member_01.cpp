struct Nec {
	int a : 4{2};	//valid at C++20. Invalid at C++17
	int b : 4 = 5;  // Valid at C++20. Invalid at C++17
};
