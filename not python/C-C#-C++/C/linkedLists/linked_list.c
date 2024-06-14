#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../random/randarray.h"

/*
// Function to check if the list is empty
bool is_empty(cell *lst) {
    return (lst == NULL);
}*/ // ==============================================> DEAL WITH THIS LATER

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Prints the list, formated
void printlist(cell *lst){
	
	if (lst == NULL){
		fprintf(stderr, "NO EL LINKED LISTO!!!\n");
	}
	else{
		cell *p;
		printf("HEAD -> ");
		for (p = lst->next; p != NULL; p = p->next){
			printf ("%d -> ", p->contents);
		}
		printf("NULL");
		printf("\n");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Counts the number of elements in list
int countlist(cell *lst){
	if (lst == NULL){
		fprintf(stderr, "NO EL LINKED LISTO!!!\n");
		return -1;
	}
	else
	{
		cell *p;
		int count = 0;
		for (p = lst->next; p != NULL; p=p->next){
			count++;
		}
		return count;	
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Gets the height of a given cell
int cellheight(cell *lst, int k){
	
	if (lst == NULL){
		fprintf(stderr, "NO EL LINKED LISTO!!!\n");
		return -1;
	}

	if (k < 0){
		fprintf(stderr, "Error: position value must be positive!\n");
		return -1;
	}

	int height;
	cell *p;
	p = lst->next;
	while(k > 0) {
	    p = p->next;
	    k--;
	}

	height = 0;
	while(p->next != NULL){
		p = p->next;
		height++;
	}
	return height;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Gets cell depth
int celldepth(cell *lst, int c){

	if (lst == NULL){
		fprintf(stderr, "NO EL LINKED LISTO!!!\n");
		return -1;
	}

	cell *p;
	p = lst->next;
	int depth = 0;
	while(p->contents != c && p->next != NULL){
		p = p->next;
		depth++;
	}

	if (p->next == NULL && p->contents != c){
		fprintf(stderr, "Error: content %d not in list!\n", c);
		return -1;
	}

	return depth;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

cell 
*find (int x, cell *lst)
{
	cell *p;
	p = lst->next;
	while (p != NULL && p->contents != x) {
		p = p->next; 
	}
	return p;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int increasinglist(cell *lst){
	cell *p;
	p = lst->next;
	while(p->next != NULL){
		if (p->contents > p->next->contents){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Gets the adress of a cell with content value x in a increasing linked list
cell *find_x_incresing(cell *lst, int x){
	if (increasinglist(lst)){
		return find(x, lst);
	}
	else{
		return NULL;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Gets the cell with the smallest value in a linked list
cell list_find_minimum(cell *lst) {
    if (lst == NULL) {
        // Handle the case where the list is empty
        fprintf(stderr, "Error: The list is empty.\n");
        exit(EXIT_FAILURE);
    }

    cell *min = lst; // Start with the first cell
    cell *p = lst->next;

    while (p != NULL) {
        if (p->contents < min->contents) {
            min = p;
        }
        p = p->next;
    }

    return *min;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int equal(cell *lst1, cell *lst2){
	cell *p, *q;
	p = lst1->next;
	q = lst2->next;
	while(p != NULL && q != NULL ) {
	    if (p->contents != q->contents){
	    	return 0;
	    }
	    p = p->next;
	    q = q->next;
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

cell *midpoint(cell *lst){
	if (lst == NULL) {
        return NULL;  // Handle empty list case
    }
	cell *slow = lst;
    cell *fast = lst;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }

    return slow;  // Slow pointer will be at the midpoint
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

// Initializes a new cell for a linked list
// Returns a pointer to the newly initialized cell
// Returns NULL if memory allocation fails
cell *initializeLL(){
	cell *lst;
	lst = malloc (sizeof (cell));
	
	if (lst == NULL){
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return NULL;
	}

	lst->next = NULL;
	return lst;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void 
insert (int x, cell *lst)
{
	cell *new;
	new = malloc (sizeof (cell));
	new->contents = x;
	
	cell *p;
	p = lst;
	while(p->next != NULL) {
	    p = p->next;
	}

	new->next = NULL;
	p->next = new;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

cell *copy(cell *lst){
	cell *cpy, *p, *q;
	cpy = initializeLL();
	p = lst->next;
	q = cpy;
	while(p != NULL) {
	    q->next = malloc (sizeof (cell));
	    q->next->contents = p->contents;
	    q->next->next = NULL;
	    q = q->next;
	    p = p->next;
	}
	return cpy;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void concatenate(cell *lst1, cell *lst2){
	cell *p, *q;
	p = lst1->next;
	q = lst2->next;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = q;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void add_content(cell *lst, int x, int k){
	cell *p, *temp, *new;

	p = lst->next;
	for (int i = 1; i < k; ++i){
		if (p == NULL){
			fprintf(stderr, "Error: List is shorter than expected.\n");
            return;
		}
		p = p->next;
	}

	temp = p->next;
	new = malloc (sizeof (cell));
	if (new == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }

	new->contents = x;
	new->next = temp;
	p->next = new;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void delete_cell (cell *p)
{
   cell *garbage;
   garbage = p;
   p->next = garbage->next;
   free (garbage);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void fillupLL(cell *lst, int n){
	if (lst == NULL){
		fprintf(stderr, "NO EL LINKED LISTO!!!\n");
	}
	else
	{
		for (int i = 0; i < n; ++i){
			insert(randInt(200, 100), lst);
		}
	}
}