#include "radixsort.h"
#include "general_sort.h"
#include <stdlib.h>

// Array of bits. A function to rearrange in increasing order an array v[] whose elements are 0s and 1s. 
// O(n)
void organize_bin(int v[], int n){

    int left = 0, right = n - 1;

    while (left < right) {
        // Move left index forward while we have 0s at the left
        while (v[left] == 0 && left < right) {
            left++;
        }

        // Move right index backward while we have 1s at the right
        while (v[right] == 1 && left < right) {
            right--;
        }

        // Swap 1 at left with 0 at right
        if (left < right) {
            int temp = v[left];
            v[left] = v[right];
            v[right] = temp;
            left++;
            right--;
        }
    }
}

// O(n²)
void organize_bin2(int v[], int n){
	int t;
	for (int i = 0; i < n; ++i) 
		if (v[i] == 1)
			for (int j = i; j < n; ++j) 
				if (v[j] == 0) t = v[j], v[j] = v[i], v[i] = t;
}
/*
void create_DNA(char c[], int n){

}*/
void organize_int_DNA(int v[], int n){
	// SUPER inefficient (almost O(n³))
	// but whatever
	
	insertionsort(v, n);

}

// This function rearranges v[0..n-1] in
// increasing order assuming that the
// elements of the array belong to the
// universe 0..R-1.

void 
countingsort (int *v, int n, int R) 
{
	int r;
	int *fp, *aux;
	fp = malloc ((R+1) * sizeof (int));
	aux = malloc (n * sizeof (int));

	for (r = 0; r <= R; ++r) 
		fp[r] = 0;
	for (int i = 0; i < n; ++i) {
		r = v[i];
		fp[r+1] += 1; 
	}
   
	// A
	for (r = 1; r <= R; ++r)
		fp[r] += fp[r-1];
	
	// B
	for (int i = 0; i < n; ++i) {
		r = v[i];
		aux[fp[r]] = v[i];
		fp[r]++;  // C
	}
   
	// D 
	for (int i = 0; i < n; ++i)
	v[i] = aux[i];

	free (fp);   
	free (aux);
}


// Rearranges in lexicographic order the
// array v[0..n-1] of strings. Each v[i]
// is a string v[i][0..W-1] whose elements
// belong to the set 0..R-1.

void 
digitalsort (byte **v, int n, int W, int R) 
{
	int *fp;
	byte **aux;
	fp = malloc ((R+1) * sizeof (int));
	aux = malloc (n * sizeof (byte *));

	for (int d = W-1; d >= 0; --d) {
		int r;
		for (r = 0; r <= R; ++r) 
			fp[r] = 0;
		for (int i = 0; i < n; ++i) {
			r = v[i][d];
			fp[r+1] += 1; 
		}
		for (r = 1; r <= R; ++r) 
			fp[r] += fp[r-1]; 
		for (int i = 0; i < n; ++i) {
			r = v[i][d];
			aux[fp[r]] = v[i]; 
			fp[r]++; 
		}
		for (int i = 0; i < n; ++i) 
			v[i] = aux[i];
	}

	free (fp);
	free (aux);
}