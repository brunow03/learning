#ifndef GRAPHS_H
#define GRAPHS_H

#define MAXV 1000

typedef struct Vertex {
	int contents;
	struct Vertex **adjacent;
	int adj_size;
} Vertex;

typedef struct Node {
	int key;
	struct Node *next;
} Node;

typedef struct GraphList {
	int V, E;
	Node *adjLnkdLst[MAXV];
} GraphList;
extern GraphList g_graphList;

typedef struct GraphMatrix {
	int array[MAXV][MAXV];
} GraphMatrix;
extern GraphMatrix g_matrix;

typedef struct StackOfInts {
	int t;
	int array[MAXV];
} StackOfInts;
extern StackOfInts g_stack;

typedef struct QueueOfInts {
	int p, r;
	int array[MAXV];
} QueueOfInts;
extern QueueOfInts g_queue;

void get_adjMatrix(int E, int V);
void print_matrix(void);
void visit_matrix(int k, int val[], int* id);
void matrix_dfs(void);

void get_adjList(int E, int V);
void visit_list(int k, int val[], int *id);
void list_dfs(int* visited);
void visit_list_bfs(int k, int val[], int *id);
void list_bfs(void);
void print_list(void);

void stack_init(void);
void push(int val);
int pop(void);
int stack_is_empty(void);
int stack_is_full(void);

void queue_init(void);
int get(void);
void put(int val);
int isfull_queue(void);
int isempty_queue(void);

#endif // GRAPHS_H

