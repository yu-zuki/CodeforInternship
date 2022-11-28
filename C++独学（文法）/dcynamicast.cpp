//dynamic_castの勉強、タイマー使用テスト

#include <iostream>
#include <array>
#include <chrono>
#include <memory>

class Timer
{
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
		auto duration = end - start;

		auto ms = duration * 0.001;

		std::cout << duration << "us(" << ms << "ms)\n";
	}
private:
	std::chrono::time_point< std::chrono::high_resolution_clock> m_StartTimepoint;
};

class Entity
{
	virtual void f() {}
};

class Player : public Entity
{

};

class Enemy : public Entity
{

};

int main()
{
#if 0

	Entity* actuallyPlayer = new Player;
	Entity* actuallyEnemy = new Enemy;

	Player* p0 = dynamic_cast<Player*>(actuallyPlayer);
	Player* p1 = dynamic_cast<Player*>(actuallyEnemy);

	std::cout << p0 << std::endl;
	std::cout << p1 << std::endl;
#else
	struct Vector2
	{
		float x, y;
	};

	std::cout << "Make Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}

	std::cout << "New Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}

	std::cout << "Make Unique\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vector2>();
	}

#endif // 0

	// __debugbreak();

	return 0;
}