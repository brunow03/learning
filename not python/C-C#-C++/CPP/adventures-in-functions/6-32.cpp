#include <iostream>

int &get(int *array, int index){
	return array[index];
}

int main(int argc, char const *argv[])
{
	int ia[10];
	for (int i = 0; i < 10; ++i)
	{
		get(ia, i) = i;
	}	
	return 0;
}