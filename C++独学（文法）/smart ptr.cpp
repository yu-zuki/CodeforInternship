//スマートポインタの勉強

#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
	Entity* m_p;
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity " << std::endl;
	}

	void print()
	{}


};
int main()
{
	{
		std::weak_ptr <Entity> e0;
		{
			/*std::unique_ptr <Entity> entity = std::make_unique<Entity>();
			entity->print();*/

			/*std::shared_ptr<Entity> entity = std::make_shared<Entity>();
			std::shared_ptr<Entity> e0 = entity;*/

			std::shared_ptr<Entity> entity = std::make_shared<Entity>();
			e0 = entity;
		}
	}
	return 0;
}