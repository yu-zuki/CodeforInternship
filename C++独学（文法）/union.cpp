//unionの勉強

#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
	union 
	{
		struct
		{
			float x, y, z, w;
		};
		struct 
		{
			Vector2 a, b;
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << " , " << vector.y << std::endl;
}

int main()
{

	Vector4 vector = { 1.f,2.f,3.f,4.f };
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cin.get();
}
