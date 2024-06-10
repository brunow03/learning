static struct node
{
	int key;
	struct node *next;
};

static struct node *head, *z, *t;

queueinit()
{
	head = (struct node *) malloc(sizeof *head);
	z = (struct node *) malloc(sizeof *z);
	head->next = z;
	head->key = 0;
	z->next = z;
}

insert(int v)
{
	t = (struct node *) malloc(sizeof *t);
	t->key = v;
	t->next = head->next;
	head->next = t;
}

remove()
{
	static struct node *x;
	x = (struct node *) malloc(sizeof *);
	t = head->next;
	x = t;
	while(1){
		t = x->next;
		if(t->next == z){
			free(t);
			x->next = z;
			break;
		}
		x = t->next;
	}
}

int queueempty()
{
	return head->next == z;
}