//データがメモリ上ある位置を勉強

#include <iostream>

struct Entity
{
    int x,y;
};

int main()
{
    Entity e = { 5,8 };

    int y = *(int*)((char*)&e + 4);

    std::cout << y << std::endl;
}
