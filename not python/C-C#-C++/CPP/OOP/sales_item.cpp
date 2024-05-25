#include <iostream>
#include "Sales_item.h"

struct Sales_data {
	// new members: operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	// data members are unchanged from § 2.6.1 (p. 72)
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

int main()
{
	Sales_data total; // variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	
	if (std::cin >> total) {
		
		Sales_data trans; // variable to hold the running sum
		// read and process the remaining transactions
		
		while (std::cin >> trans) {
		// if we’re still processing the same book
			
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			
			else {
				// print results for the previous book
				std::cout << total << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	
	} else {
		// no input! warn the user
		
		std::cerr << "No data?!" << std::endl;
		return -1; // indicate failure
	}

	return 0;
}

