#include "hashing.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void
direct_addressing(int N, int R, char * file){
	int k, nk; // keys and number of distinct keys
	int maxf = 0; // most frequent key

	int *tb;
	tb = malloc (R * sizeof (int));
	if (tb == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
	
	for (int i = 0; i < R; ++i) {
		tb[i] = 0;
	}

	FILE *fptr;
	fptr = fopen(file, "r");
	if (fptr == NULL) {
        fprintf(stderr, "Error opening file.\n");
        free(tb);
        return;
    }
	nk = 0;

	// STARTS TIME
	clock_t endTime, startTime; 
	startTime = clock();

	while( fscanf(fptr, "%d", &k) == 1) {
		if (k < 0 || k >= R) {
            fprintf(stderr, "Key out of range: %d\n", k);
            continue;
        }

		if (tb[k] == 0) {
			nk++;
		}

		tb[k]++;

		if (tb[k] > tb[maxf]) {
			maxf = k;
		}
	}

	// END TIME
	endTime = clock();

	fclose(fptr);

	printf("\nNumber of distinct keys: %d\n", nk);
	printf("Most frequent key: %d\n", maxf);
	printf("It\'s frequency: %d\n", tb[maxf]);
	printf("Elapsed time (n of clocks): %ld\n", endTime - startTime);

	free(tb);
}
/*
static void contabiliza (int ch) {
	celula *p;
	p = tb;
	while (p != NULL && p->chave != ch)
		p = p->prox;
	if (p != NULL) 
		p->ocorr += 1;
	else {
		p = malloc (sizeof (celula));
		p->chave = ch;
		p->ocorr = 1;
		p->prox = tb;       
		tb = p;       
	}
}*/