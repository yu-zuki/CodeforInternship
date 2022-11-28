//c++ Threadの勉強

#include <iostream>
#include <thread>
#include <conio.h>
#include <Windows.h>

static bool sb_dowork = false;

void doWork()
{
	using namespace std::literals::chrono_literals;

	while (!sb_dowork)
	{
		std::cout << "work......" << std::endl;
		std::this_thread::sleep_for(0.1s);
	}
}

int main()
{
	std::thread worker(doWork);		//関数ポインタを渡す　

	std::cin.get();
	sb_dowork = true;

	worker.join();					//thread joining	このthreadの処理が全部完成するまで、待つ。　　

	std::cout << "Finisshed";

}