#include "../include/name_pairs.hpp"

namespace Name_pairs {

	// Member function definitions
	Name_pairs::Name_pairs(std::vector<std::string> names_init, std::vector<double> ages_init)
		: names{names_init}, ages{ages_init}
	{
	}

	Name_pairs::Name_pairs() = default;

	void Name_pairs::read_names(){
		std::string input_name;
		while(std::cin >> input_name && input_name != "end") {
			// check valid input //
			// title case here // 	
			names.push_back(input_name);
		}
	}

	void Name_pairs::read_ages(){
		for(const std::string &name : names) {
			std::cout << name << "\'s age: ";

			double age;
			while(std::cin >> age && !(age >= 0 && age < 200)) {
				std::cout << "Wrong date!" << std::endl;
				/*
				std::cin.clear();  // Clear the error flag on cin
            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
				*/
				std::cout << name << "\'s age: ";
			}
			
			ages.push_back(age);
		}
	}
	
	void Name_pairs::sort_names(){
		std::vector<std::pair<std::string,double>> temp_pair_vector;
		for (int i = 0; i < names.size(); ++i){
			temp_pair_vector.push_back(std::make_pair(names[i],ages[i]));
		}

		// sort based on first
		std::sort(temp_pair_vector.begin(), temp_pair_vector.end()); 

		// Clears original vectors
		names.clear();
		ages.clear();

		// Restores them in desired order
		for(std::pair t_pair : temp_pair_vector) {
			names.push_back(t_pair.first);
			ages.push_back(t_pair.second);	
		}
	}

	const std::vector<std::string> &Name_pairs::getnames() const {
		return names;
	}

	const std::vector<double> &Name_pairs::getages() const {
		return ages;
	}

	bool operator==(const Name_pairs& a, const Name_pairs& b){
		return a.getnames() == b.getnames() && a.getages() == b.getages();
	}

	bool operator!=(const Name_pairs& a, const Name_pairs& b){
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& os, const Name_pairs& pairs){
		
		const std::vector<std::string> &names = pairs.getnames();
		const std::vector<double> &ages = pairs.getages();
		
		for(int i = 0; i < names.size(); ++i){
			os << names[i] << "\t\t\t" << ages[i] << std::endl;
		}

		return os;
	}

}	// Name_pairs
