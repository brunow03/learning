#ifndef GRAPHS_H
#define GRAPHS_H

#define maxV 50

typedef struct vertex vertex; 
struct vertex {
	int contents;
	struct vertex **adjacent;
	int adj_size;
};

typedef struct stackofnodes stackofnodes;
struct stackofnodes {
	int t;
	vertex* nodes[maxV];
};

typedef struct adjacencyMatrix adjacencyMatrix;
struct adjacencyMatrix {
	int MATRIX[maxV][maxV];
};

stackofnodes* createstack(void);
void push(vertex *n, stackofnodes* stack);
vertex* pop(stackofnodes* stack);
int stackisempty(stackofnodes* stack);
int stackisfull(stackofnodes* stack);

void visit(int k, stackofnodes* stack);
void listdfs(void);

#endif // GRAPHS_H

