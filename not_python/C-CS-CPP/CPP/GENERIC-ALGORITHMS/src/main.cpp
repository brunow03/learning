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
#include <map>
#include <set>

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

	// Using map
	
	// count the number of times each word occurs in the input
	/*
	std::map<std::string, size_t> word_count; // empty map from string to size_t
	std::string word;
	while (std::cin >> word){
		++word_count[word];	// fetch and increment the counter for word
	}
	for (const auto &w : word_count){// for each element in the map
		// prints the result
		std::cout << w.first << " occurs " << w.second
		 		  << ((w.second > 1) ? " times" : " time") << std::endl;
	}
	*/
	// Using a set
	
	// count the number of times each word occurs in the input
	std::map<std::string, size_t> word_count2; // empty map from string to size_t
	std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
									"the", "but", "and", "or", "an", "a"};
	std::string word;
	while (std::cin >> word)
			// count only words that are not in exclude
		if (exclude.find(word) == exclude.end())
			++word_count2[word]; // fetch and increment the counter for word

	for (const auto &w : word_count2){// for each element in the map
		// prints the result
		std::cout << w.first << " occurs " << w.second
		 		  << ((w.second > 1) ? " times" : " time") << std::endl;
	}


	return 0;
}