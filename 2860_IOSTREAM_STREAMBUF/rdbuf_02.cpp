#include <fstream>
#include <iostream>

using namespace std;

void print_file_n_times(const std::string& filename, int n)
{
	std::ifstream ifs{ filename };
	if (!ifs) {
		cerr << "dosya acilamadi\n";
		std::exit(EXIT_FAILURE);
	}
	while (n--) {
		std::cout << ifs.rdbuf();
		cout << "\n---------------------------------------------------------------\n";
		std::cout << "bir tusa basiniz: "; std::getchar();
		ifs.seekg(0);
	}
}


int main()
{
	print_file_n_times("aaa.txt", 3);
}
