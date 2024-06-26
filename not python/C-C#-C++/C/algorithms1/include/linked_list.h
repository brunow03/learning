#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct record cell;

struct record{
	int contents;
	struct record *next;
};

// Function to check if the list is empty
bool is_empty(cell *lst);

// Prints a list
void printlist(cell *lst);

// Counts the number of elements in a list
int countlist(cell *lst);

// Calculate the height of a given cell
int cellheight(cell *lst, int k);

// Calculate the depth of a given cell
int celldepth(cell *lst, int c);

// Tells if the elements of a list are in a incrasing order
int increasinglist(cell *lst);

// Finds element x in a list with elements in increasing order
cell *find_x_incresing(cell *lst, int x); // ======================> This later

// Finds the smallest element in a linked list
cell list_find_minimum(cell *lst);

// Tell if two linked list are equal
int equal(cell *lst1, cell *lst2);

// Gets the cell in the midpoints of a linked list
cell *midpoint(cell *lst);

// Initialize a linked list
cell *initializeLL();

// Insert a with contents x in a liked list
void insert (int x, cell *lst);

// Returns a copy of a linked list
cell *copy(cell *lst);

// Concatenate the second linked list in the first
void concatenate(cell *lst1, cell *lst2);

// Add a cell with content x after the kth term in a linked lst
void add_content(cell *lst, int x, int k);

// Deletes a given cell
void delete_cell(cell *p);

// Fills list up with n random elements from -100 to 100
void fillupLL(cell *lst, int n);

#endif // LINKED_LIST_H
