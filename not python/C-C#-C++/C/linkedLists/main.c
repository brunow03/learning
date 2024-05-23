#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "../ordenação/randarray.h"

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

	// Gets height of a given cell k
	k = randInt(n,0,0);
	printf("k: %d\n", k);
	printf("Cell nº%d height: %d\n", k, cellheight(lst, k));

	// Gets depth of a given cell with content c
	c = 20; //randInt(200,100,k);
	printf("c: %d\n", c);
	printf("Cell depth with content %d: %d\n", c, celldepth(lst, c));

	// Tells if the list is increasing or not
	printf("Is the list increasing: %d\n", increasinglist(lst));

	// Gets the smallest element in a linked list
	printf("List smallest element content: %d\n", list_find_minimum(lst).contents);

	// Copy the linked list
	cell *lstcpy;
	lstcpy = copy(lst);

	// Prints the copy
	printf("List copy:\n");
	printlist(lstcpy);

	// Tell if both lists are equal
	printf("Are both lists equal: %d\n", equal(lst, lstcpy));

	// Gets the cell at the midpoints of the list
	printf("Cell at midpoint content: %d\n", midpoint(lst)->contents);

	// Insert a with contents x in a liked list
	insert(121, lst);
	
	// Prints the list after inserted
	printf("List after new cell insert:\n");
	printlist(lst);

	// Yet another linked list
	cell *lst2;
	lst2 = initializeLL();

	// Fills it with n random elements
	n = randInt(50,0,5);
	fillupLL(lst2, n);

	// Prints the list
	printf("Prints new list\n");
	printlist(lst2);

	// Concatenates with the first
	concatenate(lst, lst2);

	// Prints the result
	printf("List 1 and 2 concatenation:\n");
	printlist(lst);

	/*
	// Delete first cell whatever
	delete_cell(cell *p);

	// Prints the list
	printlist(lst);*/

	return 0;
}
