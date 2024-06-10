#include <stdio.h>
#define maxV 50

int j, x, y, V, E;
int a[maxV][maxV];

adjmatrix()
{
	scanf("%d %d\n", &V, &E);
	for (x = 1; x <= V; x++)
	{
		for (y = 1; y <= V; y++)
		{
			a[x][y] = 0;
		}
	}
	for (x = 1; x <= V; X++)
	{
		a[x][x] = 1;
	}
	for (j = 1; j <= E; J++)
	{
		scanf("%c %c\n", &v1, &v2);
		x = index(v1);
		y = index(v2);
		a[x][y] = 1;
		a[y][x] = 1;
	}
}