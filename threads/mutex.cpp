#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <chrono>

using namespace std;
typedef unsigned long long ull;

int myAmount = 0;
int counter = 0;
std::mutex m;
std::mutex mtx;

void addMoney()
{
	m.lock();
	++myAmount;
	m.unlock();
}

void increaseTheCounterFor100000Time()
{
	for (int i = 0; i < 100000; ++i)
	{
		if (mtx.try_lock())
		{
			++counter;
			mtx.unlock();
		}
	}
}

int main(int argc, char const *argv[])
{
	std::thread t1(addMoney);
	std::thread t2(addMoney);

	t1.join();
	t2.join();

	cout << myAmount << endl;

	return 0;
}

