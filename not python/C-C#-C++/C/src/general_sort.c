#include "../include/general_sort.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int *v, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", v[i]);

	printf("\n");
}

void printcArray(char *v, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%c ", v[i]);

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

int *dna_to_int(char v[], int n){
	int *ret;
	ret = malloc (n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		switch (v[i]) {
			case 'A':
				ret[i] = 0;
				break;
			case 'C':
				ret[i] = 1;
				break;
			case 'G':
				ret[i] = 2;
				break;
			case 'T':
				ret[i] = 3;
				break;
		}
	}

	return ret;
}