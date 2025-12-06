#include <iostream>
#include <random>

void printRandom(std::default_random_engine e) {
	for (int i = 0; i < 10; ++i)
	{
		std::cout << e() << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	std::default_random_engine e;
	std::default_random_engine e2;

	printRandom(e);
	printRandom(e2);

	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine e3(seed);
	printRandom(e3);

	// std::cout << "Min: " << eng.min() << std::endl;
	// std::cout << "Max: " << eng.max() << std::endl;

	// std::cout << eng() << std::endl;
	// std::cout << eng() << std::endl;

	// std::stringstream state;
	// state << eng; // save the current state

	// std::cout << eng() << std::endl;
	// std::cout << eng() << std::endl;

	// state >> eng;

	// std::cout << eng() << std::endl;
	// std::cout << eng() << std::endl;	

	return 0;
}