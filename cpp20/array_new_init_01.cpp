int main()
{
	int a[]{ 1,2,3 }; // Valid

	int* p = new int[]{ 1,2,3 }; // C++17 Syntax Error. Size must be explicitly defined
								              // C++20 Valid. Deduction worked

	char* p = new char[] {"necati"}; // Valid C++20

	int* p = new int[] {1, 2, 3}; // Valid C++20

}
