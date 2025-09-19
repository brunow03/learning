#include <iostream>
#include <initializer_list>
#include "../../C/ordenação/randarray.h"

using namespace std;

int sum(initializer_list<int> lst){
	int sum = 0;
	for (auto n : lst)
		sum += n;
	return sum;
}


int main(int argc, char const *argv[])
{
	int arr[10];
	randomArray(arr, 10, 100, 0);
	cout << "Sum: " << sum({arr[0],arr[1],arr[2],arr[3],arr[4],
							arr[5],arr[6],arr[7],arr[8],arr[9]}) 
					<< endl;
	return 0;
}