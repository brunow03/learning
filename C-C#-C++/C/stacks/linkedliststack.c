#include <stdlib.h>

typedef struct cell
{
	char content;
	struct cell *next;
} cell;

cell *st;

void createstack (void){
	st = malloc (sizeof (cell));
	st->next = NULL;
}

void push (char y){
	cell *new;
	new = malloc (sizeof (cell));
	new->content = y;
	new->next = st->next;
	st->next = new;
}

char pop (void){ // assumindo pilha não vazia.
	cell *p;
	p = st->next;
	char x = p->content;
	st->next = p->next;
	free (p);
	return x;
}