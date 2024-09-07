#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int square_digits(int num) {
    vector<int> digits;
    int temp;
    while(num > 0) {
        temp = num % 10;
        digits.push_back(temp * temp);
        num /= 10;
    }
    
    reverse(digits.begin(), digits.end());
    string result;
    for(int& i : digits) {
        result += to_string(i);
    }
    
    return stoi(result);
}

int main(int argc, char const *argv[])
{
    int num = 3212;
    cout << square_digits(num) << endl;
    return 0;
}