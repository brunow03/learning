#include <stdio.h>
#include "mergesort.h"
#include "general_sort.h"
#include "randarray.h"
#include "quicksort.h"
#include <limits.h>
#include "../linkedLists/linked_list.h"
#define N 10


int main(int argc, char const *argv[])
{
	int n, k, c;
	cell *lst;
	printf ("sizeof (cell) = %ld\n", sizeof (cell));

	// Gets a random integer n < 50
	n = randInt(50,0,1);

	// Prints n
	printf("%d\n", n);

	//  Creates a linked list
	lst = initializeLL();

	// Counts the number of elements
	printf("Number of elements: %d\n", countlist(lst));

	// Fills it with n random elements
	fillupLL(lst, n);

	// Prints the list
	printlist(lst);
	
	// Counts after filled
	printf("Number of elements after filled: %d\n", countlist(lst));

	return 0;
}