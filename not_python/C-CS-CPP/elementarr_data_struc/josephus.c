#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int listInitialize(int next[], int head, int z, int x){
	head = 0;
	z = 1;
	x = 2;
	next[z] = z;
	return x;
}

void deleteNext(int t, next[], int head, int z){
	next[t] = next[next[t]];
}

int insertAfter(int v, int t, int next[], int key[], int x){
	key[x] = v;
	next[x] = next[t];
	next[t] = x;
	return x++;
}

int fillUpList(int head, int z, int key[], int next[], int N, int x){
	int i;
	int v, t;

	

	x = insertAfter( , , next, key, x);
	for (i = 0; i < N; i++)
	{
		x = insertAfter( , , next, key, x);
	}
	return x;
}

int main(int argc, char const *argv[])
{
	int next[MAX], key[MAX];
	int i, N, M;

	// x: number of items in list
	int x, head, z;

	x = listInitialize(next, head, z, x);
	x = fillUpList(head, z, key, next, N, x)

	N = 9;
	M = 5;



	i = 0;
	while()
	{


		// Reset
		if (i == N-1)
		{
			i = -1;
		}
		i++;
	}

	return 0;
}