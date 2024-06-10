#include <iostream>

int main(int argc, char const *argv[])
{
	std::string concatenated;

	concatenated.append(argv[1]);
	concatenated.append(argv[2]);

	std::cout << concatenated << std::endl;

	return 0;
}