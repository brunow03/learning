#include "quicksort.h"
#include <stddef.h>
#include "../linkedLists/linked_list.h"

void positives_and_negatives(int v[], int n){
	int temp;
	for (int i = 0; i < n; ++i){
		if (v[i] > 0){
			for (int j = i+1; j < n; j++){
				if (v[j] < 0){
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
					j = n;
				}
			}
		}
	}
}

/*
void even_odd_linked_list(cell *head){
	if (head == NULL) {
        // List is empty, nothing to remove
        return;
    }

    cell *current = head;
    current = current->next;
    while(current != NULL) {
    	if (current->contents % 2 != 0) // se é ímpar
    	{
    		while() {
    		     code 
    		}
    	}
    	else // se é par
    	{ 

    	}
    	current = current->next;
    }
}*/
