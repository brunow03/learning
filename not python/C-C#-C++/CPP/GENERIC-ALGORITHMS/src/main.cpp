#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <iterator>
#include "genericalgorithms.hpp"
#include "test.hpp"

int main(int argc, char const *argv[])
{
	
	// Write a lambda that takes two ints and returns their sum.
	auto sum_lambda = [] (int a, int b) -> int { return a + b; };
	int a, b;
	a = 5; b = 8;
	std::cout << sum_lambda(a,b) << std::endl;

	int n1;
	auto sum_lambda2 = [n1] (int n2) -> int { return n1 + n2; };

	check();
	checking();

	std::vector<int> vec;
	for (int i = 1; i < 10; ++i)
		vec.push_back(i);

	std::vector<int> vecb, vecf, veci;
	std::list<int> lst;
    std::copy(vec.begin(), vec.end(), std::inserter(veci, veci.begin()));
    std::copy(vec.begin(), vec.end(), std::back_inserter(vecb));
    std::copy(vec.begin(), vec.end(), std::front_inserter(lst));

    std::cout << "og vector: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "Vector with inserter: ";
    for (int n : veci) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "back_inserter: ";
    for (int n : vecb) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "front_inserter: ";
    for (int n : lst) std::cout << n << " ";
    std::cout << std::endl;

	return 0;
}