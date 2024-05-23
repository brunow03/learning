#include "randarray.h"
#include <stdlib.h>
#include <time.h>

void randomArray(int v[], int n, int p, int q){
	srand(time(NULL));
	for (int i = 0; i < n; ++i){
		v[i] = rand() % p - q;
	}
}

int randInt(int n, int m, int seed){
	srand(time(NULL) + seed);
	return rand() % n - m;
}