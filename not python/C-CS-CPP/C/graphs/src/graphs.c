#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>

StackOfInts g_stack;
GraphMatrix g_matrix;
QueueOfInts g_queue;
GraphList g_graphList;

static int node_index(char c) {
	return ((int) (c - 'A')) + 1;
}

static char node_char(int i) {
	return ((char)(i - 1)) + 'A';
}

void get_adjMatrix(int E, int V) {
	if (V > MAXV) printf("Error: number of vertices out of bound.\n");
	else {
		char v1, v2;
		int x, y;
		for (int i = 1; i <= g_graphList.V; ++i) {
			for (int j = 1; j <= g_graphList.V; ++j) {
				if (i == j) g_matrix.array[i][j] = 1;
				else g_matrix.array[i][j] = 0;
			}
		}
		for (int i = 1; i <= g_graphList.E; ++i) {
			scanf("%c %c", &v1, &v2);
			x = node_index(v1); y = node_index(v2);
			g_matrix.array[x][y] = g_matrix.array[y][x] = 1;
		}
	}
}

void print_matrix() {
	for (int i = 1; i <= g_graphList.V; ++i) {
		for (int j = 1; j <= g_graphList.V; ++j) {
			printf("%d \n", g_matrix.array[i][j]);
		}
		printf("\n");
	}
}

void get_adjList(int E, int V) {
	int x, y;
	char v1, v2;
	Node *t, *z;
	z = (Node *) malloc(sizeof *z);
	z->next = z;
	g_graphList.V = V; g_graphList.E = E;
	for (int i = 1; i <= g_graphList.V; ++i) g_graphList.adjLnkdLst[i] = z;
	for (int i = 1; i < g_graphList.E; ++i) {
		scanf("%c %c\n", &v1, &v2);
		x = node_index(v1); y = node_index(v2);
		t = (Node *) malloc(sizeof *t);
		t->key = x; t->next = g_graphList.adjLnkdLst[y]; g_graphList.adjLnkdLst[y] = t;
		t = (Node *) malloc(sizeof *t);
		t->key = y; t->next = g_graphList.adjLnkdLst[x]; g_graphList.adjLnkdLst[x] = t;
	}
}

void visit_list(int k, int val[], int *id) {
	Node *t;
	int m, min;
	val[k] = ++(*id);
	for (t = g_graphList.adjLnkdLst[k]; t != t->next; t = t->next) {
		if (val[t->key] == 0) { 
			printf("%c ", node_char(t->key));
			visit_list(t->key, val, id);
		}
	}
}

void list_dfs(int *visited) {
	int k, id;
	int val[MAXV];
	for (k = 1; k <= g_graphList.V; k++) val[k] = 0;
	for (k = 1; k <= g_graphList.V; k++) { 
		if (val[k] == 0) {
			printf("%c ", node_char(k));
			visit_list(k, val, &id);
			printf("\n");
		}
	}
}

void visit_list_bfs(int k, int val[], int *id) {
	Node *t;
	put(k);
	while (!isempty_queue()) {
		k = get();
		val[k] = ++(*id);
		for (t = g_graphList.adjLnkdLst[k]; t != t->next; t = t->next) {
			if (val[t->key] == 0) {
				put(t->key);
				val[t->key] = -1;
			}
		}
	}
}

void list_bfs() {
	int k;
	int val[MAXV]; int id = 0;
	queue_init();
	for (k = 1; k <= g_graphList.V; k++) val[k] = 0;
	for (k = 1; k <= g_graphList.V; k++) if (val[k] == 0) visit_list_bfs(k, val, &id);
}

void print_list(void) {
	Node *t;
	for (int i = 1; i <= g_graphList.V; ++i) {
		for (t = g_graphList.adjLnkdLst[i]; t != t->next; t = t->next) {
			printf("%c ", node_char(t->key));
		}
		printf("\n");
	}
}

void visit_matrix(int k, int val[], int* id) {
	int t;
	val[k] = ++(*id);
	for (t = 1; t <= g_graphList.V; t++) {
		if (g_matrix.array[k][t] != 0) {
			if (val[t] == 0) {
				visit_matrix(t, val, id);
			}
		}
	}
}

// void matrix_dfs() 

void stack_init() {
	g_stack.t = 0;
}

void push(int val) {
	g_stack.array[++(g_stack.t)] = val;
}

int pop() {
	return g_stack.array[(g_stack.t)--];
}

int stack_is_empty() {
	return g_stack.t == 0;
}

int stack_is_full() {
	return g_stack.t == MAXV-1;
}

void queue_init(void) {
	g_queue.p = g_queue.r = 0;
}

int get(void){
	if (isempty_queue()) printf("Error: queue is empty.\n");
	else if (g_queue.p == MAXV - 1) {
		g_queue.p = 0;
		return g_queue.array[MAXV - 1];
	}
	else return g_queue.array[(g_queue.p)++];
}

void put(int val){
	if (g_queue.r == MAXV-1) {
		if (!isfull_queue()) {
			g_queue.r = 1;
			g_queue.array[0] = val;
		}
		else printf("Error: queue is full.\n");
	}
	else if (!isfull_queue()) g_queue.array[(g_queue.r)++];
	else printf("Error: queue is full.");
}

int isfull_queue(void) {
	return g_queue.p == 0 && g_queue.r == MAXV;
}

int isempty_queue(void) {
	return g_queue.p == g_queue.r - 1;
}
