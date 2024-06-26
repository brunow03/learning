// Take a design decision different from the one above: 
// suppose that the part of the array occupied by the queue is qu[p..r].  
// Write the code of the functions enqueue, dequeue, isempty, and isfull. 

#include <stdlib.h>
#define N 1000

int qu[N];
int p, r;

int dequeue (void) {
	return qu[p++];
}

void enqueue (int y) {
	qu[r++] = y;
}

int *createqueue(void){
	return array[N];
}

int isempty(int array[]){
	return p == r;
}

int isfull(int array[]){
	return r == N;
}