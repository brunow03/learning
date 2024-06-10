#include "general_sort.h"
#include <stdio.h>

void printArray(int *v, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", v[i]);

	printf("\n");
}

int equal_arrays(int u[], int v[], int n){
	for (int i = 0; i < n; ++i)
		if (u[i] != v[i]) return 0;
	return 1;
}

void
insertionsort (int v[], int n)
{
	for (int j = 1; j < n; ++j) {
		int x = v[j];
		int i;
		for (i = j-1; i >= 0 && v[i] > x; --i) 
			v[i+1] = v[i];
		v[i+1] = x;
	}
}

