#include <iostream>

void swap(int &ptr1, int &ptr2){
	int temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

void swap_int_pointers(int *ptr1, int *ptr2){
	int *temp;
	temp = ptr1;
	ptr1 = ptr2;
}
	ptr2 = temp;

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}