#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct matrix;

bool compare(const matrix& A, const matrix& B);
vector<int>::iterator change_val(int n, vector<int>::iterator it);

namespace mynamespace {
	bool is_empty(const string &s) {
		return s.empty();
	}
}

bool has_cap_letters(const string& s) {
	for (auto c : s)
		if (c >= 'A' && c <= 'Z')
			return true;
	return false;
}

void to_lower(string& s){
	for (auto &c : s){
		if (c >= 'A' && c <= 'Z'){
			c += 32;
		}
	}
}

int main(int argc, char const *argv[])
{
	cout << mynamespace::is_empty("") << endl;
	const string teste = "lkdmKMALKMsAML";
	cout << "capital: " << has_cap_letters(teste) << endl;
	string teste2 = "lkdmKMALKMsAML";
	to_lower(teste2);
	cout << "to lower: " << teste2 << endl;
	return 0;
}

/*

Exercise 6.19: Given the following declarations, determine which calls are legal and
which are illegal. For those that are illegal, explain why.

double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

(a) calc(23.4, 55.1); illegal. functions expects only 1 parameter
(b) count("abcda", ’a’); legal
(c) calc(66); legal
(d) sum(vec.begin(), vec.end(), 3.8); ilegal. 3.8 is not int

*/