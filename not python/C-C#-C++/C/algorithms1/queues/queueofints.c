#include <stdlib.h>
#include "queueofints.h"
#define N 100
#define TRUE 1
#define FALSE 0

int qu[N];
int p, r;
int dist[N];

int dequeue (void) {
	return qu[p++];
}

void enqueue (int y) {
	qu[r++] = y;
}

void createqueue(void){
	p = r = 0;
}

int isempty(int array[]){
	return p >= r;
}

int isfull(int array[]){
	return r >= N;
}

void resize (void) {
	N *= 2;
	qu = realloc (qu, N * sizeof (int));
}

// This function receives a matrix A that
// represents the interconnections between
// cities 0..N-1 and fills in the array dist
// in such a way that dist[i] is the distance
// from city c to city i, for each i.

void distances (int A[][N], int c) {
	for (int j = 0; j < N; ++j)  dist[j] = N;
	dist[c] = 0;
	createqueue ();
	enqueue (c);

	while (! isempty()) { 
    	int i = dequeue ();
    	for (int j = 0; j < N; ++j)
        	if (A[i][j] == 1 && dist[j] >= N) {
        		dist[j] = dist[i] + 1;
            	enqueue (j);
        	}
   }
}

int distances_a_to_b (int A[][N], int a, int b) {
	int found = FALSE;
	for (int j = 0; j < N; ++j)  dist[j] = N;
	dist[a] = 0;
	createqueue ();
	enqueue (a);

	while (! isempty() && !found) { 
    	int i = dequeue ();
    	for (int j = 0; j < N && !found; ++j)
        	if (A[i][j] == 1 && dist[j] >= N) {
        		dist[j] = dist[i] + 1;
            	enqueue (j);
        	}
        	if (j == b){
        		found = TRUE;
        	}
   }

   return dist[b];
}

// Size of the queue. Is the space allocated to the array qu sufficient?  
// Can the instruction enqueue (j) cause an overflow overflow the queue? 
// Ans: 