#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>

stackofnodes* createstack(void)
{
	stackofnodes* stack = (stackofnodes*)malloc(sizeof(stackofnodes));
	if (stack == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	stack->t = 0;
	return stack;
}

void push(vertex *n, stackofnodes* stack) {
	if (stackisfull(stack)) {
		fprintf(stderr, "Stack overflow\n");
		return;
	}
	stack->nodes[++(stack->t)] = n;
}

vertex* pop(stackofnodes* stack) {
	if (stackisempty(stack)) {
		fprintf(stderr, "Stack underflow\n");
		return NULL;
	}
	return stack->nodes[(stack->t)--];
}

int stackisempty(stackofnodes* stack) {
	return stack->t == 0;
}

int stackisfull(stackofnodes* stack) {
	return stack->t == maxV-1;
}
/*
void visit(vertex* k, stackofnodes* stack)
{
	vertex *t;
	push(k, stack);
	while(!stackisempty(stack)) {
		k = pop(stack);
		val[k] = ++id;
		for (t = adj[k]; t != z; t = t->next;)
		{
			if (val[t->v] == 0)
			{
				push(t->v);
				val[t->v] = -1;
			}
		}
	}
}*/
/*
void listdfs(void)
{
	int k;
	stackinit();
	for (k = 1; k < V; k++) val[k] = 0;
	for (k = 1; k <= V; k++)
		if (val[k] == 0) visit(k);
}*/