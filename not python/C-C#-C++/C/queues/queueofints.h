#ifndef QUEUEOFINTS_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define QUEUEOFINTS_H
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

void resize(void);

void distances (int A[][N], int c);

int distances_a_to_b (int A[][N], int a, int b);

#endif