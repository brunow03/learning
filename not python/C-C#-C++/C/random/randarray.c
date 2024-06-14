#include "randarray.h"
#include <stdlib.h>
#include <time.h>

void randomArray(int v[], int n, int p, int q){

	for (int i = 0; i < n; ++i)
		v[i] = rand() % p - q;
}

int randInt(int n, int m){
	return rand() % n - m;
}

void bin_rand_array(int v[], int n){
	for (int i = 0; i < n; ++i)
		v[i] = rand() % 2;
}

void DNA_rand_array(char v[], int n){
	char a, c, g, t;
	a = 'A'; c = 'C'; g = 'G'; t = 'T';
	int base;

	for (int i = 0; i < n; ++i)
	{
		base = rand() % 4;
		switch (base) {
			case 0:
				v[i] = a;
				break;
			case 1:
				v[i] = c;
				break;
			case 2:
				v[i] = g;
				break;
			case 3:
				v[i] = t;
				break;
		}
	}
}