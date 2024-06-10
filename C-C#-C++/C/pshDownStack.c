static struct node
{
	int key;
	struct node *next;
};

static struct node *head, *z, *t;

stackinit()
{
	head = (struct node *) malloc(sizeof *head);
	z = (struct node *) malloc(sizeof *z);
	head->next = z;
	head->key = 0;
	z->next = z;
}

push(int v)
{
	t = (struct node *) malloc(sizeof *t);
	t->key = v;
	t->next = head->next;
	head->next = t;
}

int pop()
{
	int x;
	t = head->next;
	head->next = t->next;
	x = t->key;
	free(t);
	return x;
}

int stackempty()
{
	return head->next == z;
}