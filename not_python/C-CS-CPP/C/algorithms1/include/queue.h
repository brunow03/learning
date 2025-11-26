#ifndef QUEUE_H
#define QUEUE_H
#define Q_MAX_SIZE 1000

typedef struct queue queue; 

struct queue {
	int p;
	int r;
	int qu[Q_MAX_SIZE];
};

int dequeue(queue q);
void enqueue(queue q, int y);
queue createqueue(void);
int isemptyqueue(queue q);
int isfullqueue(queue q);
int queuelength(queue q);
void distances (int A[][Q_MAX_SIZE], int c);

#endif // QUEUE_H
  
