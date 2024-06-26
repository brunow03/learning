#include <stdlib.h>
#include "queueofintscircular.h"
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