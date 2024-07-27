#include <iostream>
#include "Sales_item.h"

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

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

