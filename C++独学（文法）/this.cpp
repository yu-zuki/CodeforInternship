//thisポインタの勉強

#include <iostream>
#include <string>

using namespace std;
class Entity;

void printEntity(Entity* e);

class Entity
{
public:
	int x, y;
	Entity(int x,int y)
		:x(0),y(0)
	{
		this->x = x;
		this->y = y;
		printEntity(this);
	}

private:

};



int main()
{
	Entity e(100, 100);

	return 0;
}

void printEntity(Entity* e)
{
	std::cout << e->x << " " << e->y;
}