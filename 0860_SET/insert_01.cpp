#include <iostream>
#include <set>

int main()
{
	using namespace std;

	set<int> s{ 2, 3, 5, 6, 8, 23, 98, 123, 187 };

	for (auto val : s)
		cout << val << ' ';

	cout << "\nset size : " << s.size() << '\n';
	cout << "enter the value to insert : ";
	int x; 
	cin >> x;

	if (auto [iter, success] = s.insert(x); success) {
		cout << "the value inserted... " << *iter << '\n';
	}
	else {
		cout << "the value not inserted, the set has this value : " << *iter << '\n';
	}

	cout << "set size : " << s.size() << '\n';
	for (auto val : s)
		cout << val << ' ';
}

