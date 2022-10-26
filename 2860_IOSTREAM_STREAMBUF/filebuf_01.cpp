#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	using namespace std;
	
	filebuf buf;
	
	ostream output(&buf);
	istream input(&buf);

	buf.open("example.dat", ios::in | ios::out | ios::trunc);
	vector<string> svec{ "ali", "murat", "kayhan", "gizem" };

	for (const auto &s : svec) {
		output << s << flush;
		input.seekg(0); 
		char c;
		while (input.get(c)) {
			cout.put(c);
		}
		cout << endl;
		input.clear(); 
	}
}
