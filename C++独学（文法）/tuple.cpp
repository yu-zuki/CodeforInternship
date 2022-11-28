//c++ 17 tuple‚Ì•×‹­

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

	//c++ 17@tuple
	auto [name, age] = CreatePerson();

	std::cout << "nameF" << name << "\n";
	std::cout << "ageF" << age << "\n";

	return 0;
}