#include <iostream>

int swap_ints(int n, int *p){
	if(n > *p) return n;
	else return *p;
}

void swap_int_pointers(int *ptr1, int *ptr2){
	int *temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}