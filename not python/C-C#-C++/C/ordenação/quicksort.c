#include "quicksort.h"
#include <stddef.h>
#include "../linkedLists/linked_list.h"
#include <stdlib.h>
#include "general_sort.h"

static void truncated_sort(int v[], int n){
	insertionsort(v, n);
}

void positives_and_negatives(int v[], int n){
	int temp;
	for (int i = 0; i < n; ++i){
		if (v[i] > 0){
			for (int j = i+1; j < n; j++){
				if (v[j] <= 0){
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
					j = n;
				}
			}
		}
	}
}


void even_odd_linked_list(cell *head_even, cell *head_odd){
	if (head_odd == NULL || head_even == NULL) {
        // List is empty, nothing to remove
        return;
    }

    cell *current_even, *current_odd;
	
	current_odd = head_odd;
	current_even = head_even;
    while (current_even->next != NULL)
    {
    	if (current_even->next->contents % 2 != 0)
    	{
    		// Copies to odd list
    		current_odd->next = malloc(sizeof(cell));
    		current_odd->next->contents = current_even->next->contents;
    		current_odd->next->next = NULL;
    		current_odd = current_odd->next;
    			
    		// Deletes element in even list
    		cell *garbage;
    		garbage = current_even->next;
    		current_even->next = garbage->next;
    		free (garbage);
    	}
    	else {
    		current_even = current_even->next;
    	}
    }


}

// Digamos que um vetor v[p..r] está separado se existe j em p..r tal que  v[p..j-1] ≤ v[j] < v[j+1..r].  
// Escreva um algoritmo que decida se v[p..r] está separado. 
// Em caso afirmativo, o seu algoritmo deve devolver o índice j.

int is_separated(int v[], int p, int r){
	int i, k;
	for (int j = p; j < r; ++j) {
		i = p; 
		k = r;
		while (v[i] <= v[j] && i < j) i++;
		while (v[k] > v[j] && k > j) k--;
		if (i == j && k == j) return j;
	}

	return -1;
}

// Rearranges the elements of the array
// v[p..r], with p <= r, and returns j
// in p..r such that v[p..j-1] <= v[j] < v[j+1..r].

static int 
partition(int v[], int p, int r){
	int c = v[r]; // pivot
	int t, j = p;

	for (int k = p; /*A*/ k < r; ++k)
		if (v[k] <= c) {
			t = v[j], v[j] = v[k], v[k] = t;
			++j; 
		} 
	
	t = v[j];
	v[j] = v[r];
	v[r] = t;
	
	return j;
}

// Recursive version.
static int
rpartition(int v[], int p, int r, int j){
	if (p == r){
		int t = v[j];
		v[j] = v[r];
		v[r] = t;
		return j;
	}
	else if (v[p] <= v[r]){
		int t = v[j];
		v[j] = v[p];
		v[p] = t;
		return rpartition(v, ++p, r, ++j);
	}
	else return rpartition(v, ++p, r, j);
}

// Quicksort functiosn
// This function rearranges an array
// v[p..r] in increasing order.

void 
quicksort (int v[], int p, int r)
{
	if (p - r < 20)
		truncated_sort(v, p-r);
	else if (p < r) {  					// 1
		int j = partition (v, p, r);  	// 2
		quicksort (v, p, j-1);  		// 3
		quicksort (v, j+1, r);  		// 4
	}
}

void 
quick_sort (int v[], int n){
	return quicksort(v, 0, n-1);
}

