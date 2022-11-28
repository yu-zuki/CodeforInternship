//精度が高いタイマーの勉強

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

struct Timer
{
	//RAII (Resource Acquisition Is Intialization)
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

void f()
{
	Timer t;

	std::string s = "Hello...\n";

#if 0
	for (int i = 0; i < 100; i++)
	{
		s += "Hello...\n";
	}
	std::cout << s << std::endl;
#else
	for (int i = 0; i < 100; i++)
	{
		std::cout << s;
	}
	
#endif // 0
}

int main()
{
	f();
}

