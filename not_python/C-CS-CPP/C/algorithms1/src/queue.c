#include "../include/queue.h"

int dequeue(queue q){
	int x = q.qu[q.p++];
	if (q.p == Q_MAX_SIZE) q.p == 0;
	return x;
}

void enqueue(queue q, int y){
	q.qu[q.r++] = y;
	if (q.r == Q_MAX_SIZE) q.r = 0;
}

queue createqueue(void){
	queue q;
	q.r = q.p = 0;
	return q;
}

int isemptyqueue(queue q){
	return q.p == q.r;
}

int isfullqueue(queue q){
	return q.r + 1 == q.p || (q.r+1 == Q_MAX_SIZE && q.p == 0);
}

int queuelength(queue q){
	return q.r - q.p;
}

// This function receives a matrix A that
// represents the interconnections between
// cities 0..N-1 and fills in the array dist
// in such a way that dist[i] is the distance
// from city c to city i, for each i.

void distances (int A[][Q_MAX_SIZE], int c) {
	int dist[Q_MAX_SIZE];
	queue q;
	for (int j = 0; j < Q_MAX_SIZE; ++j)  dist[j] = Q_MAX_SIZE;
	dist[c] = 0;
	q = createqueue();
	enqueue(q,c);

	while (! isemptyqueue(q)) { 
		int i = dequeue (q);
		for (int j = 0; j < Q_MAX_SIZE; ++j)
			if (A[i][j] == 1 && dist[j] >= Q_MAX_SIZE) {
				dist[j] = dist[i] + 1;
			enqueue(q,j);
		}
	}

}