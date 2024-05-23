#define maxV 1000

struct node
{	int v; struct node *next;	};

int j, x, y, V, E;

struct node *t, *z;
struct node *adj[maxV];

adjlist()
{
	scanf("%d %d\n", &V, &E);
	z = (struct node *) malloc(sizeof *z);
	z->next = z;
	for(j = 1; j <= V; j++) adj[j] = z;
	for(j = 1; j <= E; j++)
	{
		scanf("%c %c\n", &v1, &v2);
		x = index(v1);	y = index(v2);
		t = (struct node *) malloc(sizeof *t);
		t->v = x;	t->next = adj[y];	adj[y] = t;
		t = (struct node *) malloc(sizeof *t);
		t->v = y; t->next = adj[x]; adj[x] = t;
	}
}

int val[maxV]; int id = 0;

visit(int k)
{
	struct node *t;
	val[k] = ++id;
	for (t = adj[k]; t != z; t = t->next)
		if(val[t->v] == 0) visit(t->v);

	listdfs()
	{
		int k;
		for (k = 1; k <= V; k++) val[k] = 0;
		for (k = 1; k <= V; k++)
			if(val[k] == 0) visit[k];
	}
}