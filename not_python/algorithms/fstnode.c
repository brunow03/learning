struct nodes
{
	int key;
	struct node *next;
};
struct node *head, *z, *t;
listinitialize()
{
	head = (struct node *) malloc(sizeof *head);
	z = (struct node *) malloc(sizeof *z);
	head->next = z ;
	z->next = z;
}

deletenext(struct node *t)
	{ t->next = t->next->next; }

struct node *insertafter(int v, struct node *t)
{
	struct node *x;
	x = (struct node *) malloc(sizeof *x);
	x->key = v;
	x->next = t->next;
	t->next = x;
	return x;
}