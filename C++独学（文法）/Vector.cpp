//Vectorの最適化勉強

#include <iostream>
#include <string>
#include <vector>

class Vertex
{
private:
	float x, y, z;
public:
	Vertex(float x,float y, float z)
		:x(x),y(y),z(z)
	{
	}
	Vertex(const Vertex& vertex)
		:x(vertex.x),y(vertex.y),z(vertex.z)
	{
		std::cout << "Copoed!" << std::endl;
	}

	friend std::ostream& operator<< (std::ostream& stream, const Vertex& vertex);
};
std::ostream& operator<< (std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z << std::endl;
	return stream;
}

void Function(const std::vector<Vertex>& ver)
{

}
int main()
{

	std::vector<Vertex> vertex;
	//サイズ指定
	vertex.reserve(3);

	vertex.emplace_back(1, 2, 3 );
	vertex.emplace_back( 4, 5, 6 );
	vertex.emplace_back( 7, 8, 9 );

	//Function(vertex);

	for (Vertex& ver : vertex)	{
		std::cout << ver;
	}

	//特定な値を消す
	vertex.erase(vertex.begin() + 1);

	//配列を消す
	vertex.clear();

	std::cin.get();
	return 0;
}