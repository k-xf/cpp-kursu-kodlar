//C++ Core Guidelines örneği

enum class Alert {Red, Yellow, Green};

void func()
{
	throw Alert::Red;
}

int main()
{
	try {

	}
	catch (Alert a) {
		//...
	}
}
