#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *next;
};

int exchange(struct node *t, struct node *u, struct node *z);

int movenexttofront(struct node *t, struct node *head, struct node *z);

void printList(struct node *head, struct node *z);

void fillList(struct node *head, struct node *z);

void listSetUp(struct node *head, struct node *z);

int main(int argc, char const *argv[])
{
	int n;
	struct node *head, *z;
	head = (struct node *) malloc(sizeof *head);
	z = (struct node *) malloc(sizeof *z);

	// Inicializando a lista
	listSetUp(head, z);
	
	// Preenchendo a lista já inicializada
	fillList(head, z);

	// Imprimindo a lista
	printList(head, z);

	struct node *t, *u;
	int _;
	t = head->next->next->next;
	u = head->next->next->next->next->next->next->next->next->next->next;
	_ = exchange(t, u, z);

	printList(head, z);
	
	printf("\n");
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////

int movenexttofront(struct node *t, struct node *head, struct node *z)
{
	if (t->next->next == z)
	{
		return 0;
	}
	else{
		struct node *x, *y;
		x = (struct node *) malloc(sizeof *x);
		y = (struct node *) malloc(sizeof *y);
		x = t->next->next;
		y = x->next;
		t->next = y;
		x->next = head->next;
		head->next = x;
		return 1;
	}
}

void printList(struct node *head, struct node *z)
{
	printf("\n");
	struct node *x;
	//x = (struct node *) malloc(sizeof *x);

	x = head->next;
	while (x->next != z){
		printf("%d -> ", x->key);
		x = x->next;	
	}
}

void fillList(struct node *head, struct node *z)
{
	int n;
	struct node *x;
	x = (struct node *) malloc(sizeof *x);
	x = head->next;
	scanf("%d", &n);
	x->key = n;
	while (1){
		//printf("%d\n", t->key);
		x->next = (struct node *) malloc(sizeof *x);
		x = x->next;
		scanf("%d", &n);
		if (n == -1)
			break;
		x->key = n;
	}
	x->next = z;
}

void listSetUp(struct node *head, struct node *z)
{
	head->next = z;
	z->next = z;
}

int exchange(struct node *t, struct node *u, struct node *z)
{
	if (t->next->next == z || u->next->next == z)
	{
		return 0;
	}
	else{
		struct node *x, *y;
		
		x = t->next;
		y = u->next;

		t->next = y;
		u->next = x;

		struct node *temp;
		temp = x->next;
		x->next = y->next;
		y->next = temp;

		return 1;
	}
}