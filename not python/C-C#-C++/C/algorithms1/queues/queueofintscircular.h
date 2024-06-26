#ifndef QUEUEOFINTSCIRCULAR_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define QUEUEOFINTSCIRCULAR_H
#define TRUE 1
#define FALSE 0


extern int qu[N];
extern int p, r;
extern int dist[N];


int dequeue (void);

void enqueue (int y);

int *createqueue(void);

int isempty(int array[]);

int isfull(int array[]);

#endif