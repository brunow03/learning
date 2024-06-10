#include "mergesort.h"
#include <stdlib.h>
#include <stdio.h>

// A função recebe vetores crescentes v[p..q-1] 
// e v[q..r-1] e rearranja v[p..r-1] em ordem 
// crescente.

static void
merge (int p, int q, int r, int v[])
{
	int *w;
	w = malloc ((r-p) * sizeof (int));

	int i, j, k;
	i = p; j = q;
	for (k = 0; k < r-p; ++k) {
		if (j >= r || (i < q && v[i] <= v[j])) 
			w[k] = v[i++];
		else 
			w[k] = v[j++];}
	/*
	int i = p, j = q;
	int k = 0;
	while (i < q && j < r) 
	{
		if (v[i] <= v[j])  w[k++] = v[i++];
		else  w[k++] = v[j++];
	}
	while (i < q)  w[k++] = v[i++];
	while (j < r)  w[k++] = v[j++];
	*/

	/*
	while (k < r-p) {
		while (i < q && v[i] <= v[j]) 
			w[k++] = v[i++];
		while (j < r && v[j] <= v[i]) 
			w[k++] = v[j++]; }
	*/
	for (i = p; i < r; ++i)  v[i] = w[i-p];
	free (w);
}
	
	
	

// This function receives increasing arrays 
// v[p..q-1] and v[q..r-1] and rearranges
// v[p..r-1] in increasing order.

static void
s_merge (int p, int q, int r, int v[])
{
	int i, j, *w;
	w = malloc ((r-p) * sizeof (int));

	for (i = p; i < q; ++i) w[i-p] = v[i];
	for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
	i = 0; j = r-p-1;
	for (int k = p; k < r; ++k)
		if (w[i] <= w[j]) v[k] = w[i++];
		else v[k] = w[j--];
	free (w);
}


// The function mergesort rearranges the
// array v[p..r-1] in increasing order.

void
mergesort (int p, int r, int v[])
{
	if (p < r-1) {              // 1
		int q = (p + r)/2;       // 2
		mergesort (p, q, v);     // 3
		mergesort (q, r, v);     // 4
		merge (p, q, r, v);      // 5
   }
}

// This function rearranges the array
// v[0..n-1] in increasing order.

void
imergesort (int n, int v[])
{
	int b = 1;
	while (b < n) {
		int p = 0;
		while (p + b < n) {
			int r = p + 2*b;
			if (r > n) r = n;
			merge (p, p+b, r, v);
			p = p + 2*b; 
		}
		b = 2*b;
	}
}
