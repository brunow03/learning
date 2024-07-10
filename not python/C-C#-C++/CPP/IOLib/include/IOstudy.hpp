#ifndef I_OSTUDY_HPP
#define I_OSTUDY_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

std::istream& exercise_8_1(std::istream& input);
void exercise_8_4(const std::string& filename, std::vector<std::string>& vector);
bool exercise_9_4(std::vector<int>::iterator& iter1, std::vector<int>::iterator& iter2, int n);
std::vector<int>::iterator exercise_9_5(std::vector<int>::iterator iter1, std::vector<int>::iterator iter2, int n);

#endif // I_OSTUDY_HPP
