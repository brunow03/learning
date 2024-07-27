#include "../include/IOstudy.hpp"

std::istream& exercise_8_1(std::istream& is) {
	std::string buff;

	while (is >> buff){
		std::cout << buff << std::endl;
	}
	
	is.clear();
	return is;
}

void exercise_8_4(const std::string& filename, std::vector<std::string>& vector){
	
	std::string temp;
	std::ifstream file_input(filename);

	while(getline(file_input, temp)){
		vector.push_back(temp);
	}
}

bool exercise_9_4(std::vector<int>::iterator& iter1, std::vector<int>::iterator& iter2, int n){
	while(iter1 != iter2) {
		if (*iter1 == n) 
			return true;
		++iter1;
	}
	return false;
}

std::vector<int>::iterator exercise_9_5(std::vector<int>::iterator iter1, std::vector<int>::iterator iter2, int n){
	while(iter1 != iter2) {
		if (*iter1 == n) 
			return iter1;
		++iter1;
	}
	return iter2;
}