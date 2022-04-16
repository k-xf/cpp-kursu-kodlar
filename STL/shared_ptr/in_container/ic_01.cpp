#include <memory>
#include "person.h"
#include <list>
#include <vector>

int main()
{
	{
		std::list<std::shared_ptr<Person>> mylist;

		mylist.emplace_back(new Person{ "Ahmet", "Yesil" });
		mylist.emplace_back(new Person{ "Ayse", "Topal" });
		mylist.emplace_back(new Person{ "Veli", "Dundar" });
		mylist.emplace_back(new Person{ "Murat", "Salih" });
		std::cout << "bir tusa basin "; (void)getchar();

		{
			std::vector<std::shared_ptr<Person>> myvec(mylist.begin(), mylist.end());
			////
			for (auto& s : myvec)
				s->set_name(s->Name() + "can");
		}

		for (auto& s : mylist)
			std::cout << *s << "\n";

		std::cout << "bir tusa basin: "; (void)getchar();
	}

	std::cout << "main devam ediyor\n";
}
