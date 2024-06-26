#include "../include/hashing.h"
#include <stdlib.h>
#include <stdio.h>


void
direct_addressing(int N, int R, char * file){
	int k, nk; // keys and number of distinct keys
	int maxf = 0; // most frequent key

	int *tb;
	tb = malloc (R * sizeof (int));
	
	for (int i = 0; i < R; ++i)
		tb[i] = 0;

	FILE *fptr;
	fptr = fopen(file, "r");
	nk = 0;
	
	while( fscanf(fptr, "%d", &k) != EOF) {

		if (tb[k] == 0)
			nk++;

		if (tb[k] > tb[maxf])
			maxf = k;

		tb[k]++;
	}
	
	fclose(fptr);

	printf("\nNumber of distinct keys: %d\n", nk);
	printf("Most frequent key: %d\n", maxf);
	printf("It\'s frequency: %d\n", tb[maxf]);

}
/*
void 
count (int k) {
	cell *tb, *p;
	p = tb;
	
	while (p != NULL && p->key != k)
		p = p->next;
	
	if (p != NULL) 
		p->occur += 1;
	else {
		p = malloc (sizeof (cell));
		p->key = k;
		p->occur = 1;
		p->next = tb;       
		tb = p;       
	}
}*/