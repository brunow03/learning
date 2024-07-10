std::string input;
	std::cout << "Test name_pairs? (type go or ign)\t";
	while(std::cin >> input && input != "ign" && input == "go") {
		
		// Test default constructor
		Name_pairs::Name_pairs myNames;

		// Test constructor
		std::vector<std::string> names{"Bruno", "Amanda"};
		std::vector<double> ages{27,20};
		Name_pairs::Name_pairs myNamest(names, ages);

		std::cout << myNamest;

		// Try reading ages before names
		myNames.read_names();
		myNames.read_ages();

		// Test sort
		myNames.sort_names();
		myNamest.sort_names();

		// Test getname
		std::vector<std::string> temp_vector;
		temp_vector = myNames.getnames();
		temp_vector.clear();

		// Test operators
		std::cout << std::boolalpha << (myNames == myNamest) << std::endl;
		std::cout << "Testing operator:\n" << myNames << std::endl;

		std::cout << "Test again? (type go or ign):\n";
	}

	std::cout << "Test books? (type go or ign)\t";
	while(std::cin >> input && input != "ign" && input == "go") {
		
		// Setting up two books
		Chrono::Date d1{1996, Chrono::Month::jul, 31};
		Chrono::Date d2;
		std::string author1, author2, title1, title2;
		author1 = "JK Rowling";
		author2 = "Georger Martin";
		title1 = "Harry Potter and the Goblet of Fire";
		title2 = "A game of thrones";
		std::string isbn1 = "159-357-456-8"; 
		int isbn2[4] = {123,789,369,5};

		Library::Book book_default;
		Library::Book book1(isbn1,title1,author1,d1,Library::Genre::fiction);
		
		Library::Book book2;
		book2.setISBN(isbn2);
		book2.settitle(title2);
		book2.setauthor(author2);
		book2.setcopyrightdate(d2);
		book2.setgenre(Library::Genre::fiction);

		// Print book1
		std::cout << book1 << std::endl;

		// Print book2
		std::cout << book2 << std::endl;

		std::cout << "Test again? (type go or ign):\n";
	}



/*
{
### `const` Keyword

1. **`const std::vector<double>&`**:
   - **First `const`**: This means that the function returns a constant reference to a `std::vector<double>`. 
   This ensures that the caller cannot modify the returned vector.
   - **Second `const`**: Placed at the end of the member function, this means that the function does not modify the 
   state of the `Name_pairs` object. It's a promise that calling this function won't change any member variables of the class.

### Returning by Reference (`&`) vs. Pointer (`*`)

- **Returning by Reference (`&`)**:
  - When you return a reference to the vector (`std::vector<double>&`), it means you are returning an alias to the original vector stored within the class. This allows the caller to access the actual vector without copying it.
  - Using references is often preferred for accessor methods because it avoids the overhead of copying the entire container and makes the intention of "direct access to member" clear.

- **Returning by Pointer (`*`)**:
  - Returning a pointer (`std::vector<double>*`) would also give access to the original vector, but it introduces additional considerations such as the possibility of `nullptr` values.
  - Pointers are less safe because they require the caller to check for `nullptr` and handle memory management more carefully.
  - In this case, there's no need for the pointer's extra flexibility since you're simply providing access to an existing member variable.

### Summary

By using `const std::vector<double>& getages() const`, you ensure:
1. **Safety**: The caller cannot modify the returned vector.
2. **Efficiency**: The function returns a reference, avoiding the cost of copying the vector.
3. **Correctness**: The function does not modify the state of the object, as promised by the `const` at the end.

By making these accessor methods `const` and returning by reference, you improve both the safety and performance of your class.
}
*/

/* 
	std::istream& is
    std::cout << is.rdstate() << std::endl;
	*/

	/*
	std::string input;
	std::vector<std::string> file_vector;
	std::cout << "Enter the file name: ";
	exercise_8_4("./aside.cpp", file_vector);

	for (int i = 0; i < file_vector.size(); ++i) {
		std::cout << file_vector[i] << std::endl;
	}
	*/
	/*
	std::istringstream iss("hello ajndk asnjdk ankjs kjans d");
    exercise_8_1(iss);
	*/
	/*
	// Exercise 8.10
	std::ifstream infile("aside.cpp");

	if (!infile) {
        std::cerr << "No data?" << std::endl;
        return -1;
    }

	std::vector<std::string> vector;
	std::string line;
	while(getline(infile, line)) {
	    vector.push_back(line);
	}

	for(const std::string& str : vector) {
		std::istringstream iss(str);
		std::string word;
		while(iss >> word) {
		    std::cout << word << std::endl;
		}
	}
	*/
	/*
	for (const auto &entry : people) { // for each entry in people
		
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) { // for each number
			if (!valid(nums)) {
				badNums << " " << nums; // string in badNums
			} 
			else 	
				// ‘‘writes’’ to formatted’s string
				formatted << " " << format(nums);
		}
		
		if (badNums.str().empty())	// there were no bad numbers
			os << entry.name << " "	// print the name
				<< formatted.str() << endl; // and reformatted numbers
		else 	// otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name
				<< " invalid number(s) " << badNums.str() << endl;
	}
	*/