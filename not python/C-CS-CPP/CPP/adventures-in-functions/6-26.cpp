#include <iostream>

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= argc; ++i)
		std::cout << argv[i] << std::endl;
	
	return 0;
}