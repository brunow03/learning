#include "randarray.h"
#include <stdlib.h>
#include <time.h>

void randomArray(int v[], int n, int p, int q){

	for (int i = 0; i < n; ++i){
		v[i] = rand() % p - q;
	}
}

int randInt(int n, int m){
	return rand() % n - m;
}
