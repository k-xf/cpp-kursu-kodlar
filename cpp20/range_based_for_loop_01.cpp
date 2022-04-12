#include <vector>

class Nec
{
public:
	std::vector<int>& get_values(); 
};

Nec get_nec(); // Decleration

int main()
{
	for (auto x : get_nec().get_values()) // DANGLING REFERENCE UNDEFINED BEHAVIOR
	{
		//...
	}

	
	for (auto necx = get_nec(); auto item : necx.get_values()) // RANGE BASE FOR LOOP.VALID C++20
	{
		//...

	}
}
