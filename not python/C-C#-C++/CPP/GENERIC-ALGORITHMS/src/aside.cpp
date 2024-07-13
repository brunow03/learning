
	std::vector<int> v{1,2,3,3,4,5,3,6,42,25,3,36,1,2,3,4,5,6,3};
	int val = 3;
	std::cout << "Count return: " << std::count(v.begin(), v.end(), val) << std::endl;
	std::string file{"./Makefile"};
	std::vector<std::string> s;
	std::string temp;
	std::ifstream inFile(file);
	
	if (inFile.is_open())	{
		while(inFile >> temp) {
		    s.push_back(temp);
		}
		inFile.close();
	}
	else {
		std::cout << "Error opening file." << std::endl;
		return 1;
	}
	std::cout << ".PHONY count: " << std::count(s.begin(), s.end(), ".PHONY") << std::endl;
	