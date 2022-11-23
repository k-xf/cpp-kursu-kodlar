class Encloser {
	class Nested{
		//friend class Encloser;
		int x;
	};
	Nested nx;
public:
	int get_x() const
	{
		return nx.x; 
	}
};
