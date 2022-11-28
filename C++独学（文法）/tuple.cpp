//c++ 17 tupleの勉強

#include <iostream>
#include <tuple>

//tuple pairs
std::tuple<std::string, int>CreatePerson()
{
	return { "yuzuki",21 };
}

int main()
{
	/*auto person = CreatePerson();*/

	//c++ 17　tuple
	auto [name, age] = CreatePerson();

	std::cout << "name：" << name << "\n";
	std::cout << "age：" << age << "\n";

	return 0;
}