#include "heapsort.h"
#include <stddef.h>
#include <stdio.h>
#define swap(A, B) {int t = (A); (A) = (B); (B) = t;}

// Receives an array v[1..m] that is a heap
// except perhaps for indices 2 and 3 and
// rearranges the array so that it becomes
// a heap.

static void 
sieve (int v[], int n) { 
	int p = 1, c = 2, x = v[1];
	while (c <= n) {
		if (c < n && v[c] < v[c+1]) ++c;
		if (x >= v[c]) break;
		v[p] = v[c];
		p = c, c = 2*p;
	}
	v[p] = x;
}

int isheap(int v[], int n){
    for (int i = n / 2; i > 0; --i){
        if (v[i] < v[2*i] || (2*i + 1 <= n && v[i] < v[2*i + 1])){
            return 0;
        }
    }
    return 1;
}

// Rearranges an array v[1..m] so that
// it decomes a heap.

void buildheap (int v[], int n)
{
	for (int k = 1; k < n; ++k) {                   
		// v[1..k] is a heap
		int c = k+1;
		while (c > 1 && v[c/2] < v[c]) {  // 5
			swap(v[c/2], v[c]);  // 6
			c /= 2;  // 7
		}
	}
}

// Rearranges the elements of array v[1..n] 
// in increasing order.

void
heapsort (int v[], int n)
{
	buildheap (v, n);
	for (int m = n; m >= 2; --m) {
		swap (v[1], v[m]);
		sieve (v, m-1);
	}
}