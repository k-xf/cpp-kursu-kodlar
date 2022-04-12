struct Data{
public:
	Data(Data&&) noexcept = default; // Valid C++20
	
  //Data(Data&&) noexcept(false) = default; // Valid C++20
};
