#include <iostream>

void reset(int &p){
	p = 0;
}

int main(int argc, char const *argv[])
{
	int n;
	n = 42;
	std::cout << "Before: " << n << std::endl;
	reset(n);
	std::cout << "After: " << n << std::endl;

	return 0;
}