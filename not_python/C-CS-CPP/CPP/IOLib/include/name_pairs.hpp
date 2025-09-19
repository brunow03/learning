#ifndef NAME_PAIRS_HPP
#define NAME_PAIRS_HPP

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

namespace Name_pairs {

	class Name_pairs {
		public:
			// Constructor & initial input
			Name_pairs(); //default connstructor
			Name_pairs(const std::vector<std::string> names, const std::vector<double> ages);

			// Scanning operations
			void read_names();
			void read_ages();

			void sort_names(); // sort by name

			const std::vector<std::string> &getnames() const;
			const std::vector<double> &getages() const;

		private:
			// core variables
			std::vector<std::string> names;
			std::vector<double> ages;
	};

	bool operator==(const Name_pairs& a, const Name_pairs& b);
	bool operator!=(const Name_pairs& a, const Name_pairs& b);
	
	std::ostream& operator<<(std::ostream& os, const Name_pairs& pairs);
	
}	// Name_pairs


#endif // CLASSES_HPP
