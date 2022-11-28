//templateの勉強

#include <iostream>
#include <string>

template<typename T>
void Print(T tvalue)
{
	std::cout << tvalue << std::endl;
}

template <typename A,int N>
class Array
{
private:
	A m_Array[N];
public:
	int GetSize()const { return N; }
};
int main()
{
	Print(5);
	Print("string");
	Print<float>(5.1f);

	Array<int, 100> iarray;
	std::cout << iarray.GetSize();

	std::cin.get();
}