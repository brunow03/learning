#include "../include/strsrch.h"
#include <stdlib.h>

// Receives arrays a[1..m] and b[1..n], with
// m >= 1 and n >= 0, and returns the number
// of occurrences of a in b.

int 
naive (byte a[], int m, byte b[], int n) 
{
	int occurs = 0;
	for (int k = m; k <= n; ++k) {
		// does a[1..m] match b[k-m+1..k]?
		int i = m, j = k;
		while (i >= 1 && a[i] == b[j]) 
			--i, --j;   
		if (i < 1) ++occurs;
	}
	
	return occurs;
}

int
consecutive_spaces(int m, byte b[], int n){
	int occurs = 0;
	byte space = ' ';
	for (int k = m; k <= n; ++k) {
		// does a[1..m] match b[k-m+1..k]?
		int i = m, j = k;
		while (i >= 1 && space == b[j]) 
			--i, --j;   
		if (i < 1) ++occurs;
	}
	
	return occurs;
}

typedef unsigned char byte;

// Receives arrays a[1..m] and b[1..n] of
// bytes, with m >= 1 and n >= 0, and
// returns the number of occurrences of
// a in b.

int 
boyermoore1 (byte a[], int m,
             byte b[], int n)
{
	int lst[256]; // the alphabet is 0..255

	// preprocessing the word a
	for (int f = 0; f < 256; ++f) lst[f] = 0;
	for (int i = 1; i <=  m; ++i) lst[a[i]] = i;

	// search word a in text b
	int occurs = 0;
	int k = m;
	while (k <= n) {
		// does a[1..m] match b[k-m+1..k]?
		int i = m, j = k;
		while (i >= 1 && a[i] == b[j]) 
			--i, --j;   
		if (i < 1) ++occurs;
		if (k == n) k++;
		else k += m - lst[b[k+1]] + 1;
	}
	return occurs;
}

// Receives a word a[1..m] with 1 <= m and
// a text b[1..n]. Returns the number of
// occurrences of a in b.

int 
boyermoore2 (byte a[], int m,
             byte b[], int n) 
{
	int *jump = malloc ((m+1) * sizeof (int));
	// our table will be jump[1..m]

	// preprocessing of word a
	int k, h, j, i;
	h = m, k = m-1;
	i = m, j = k;
	while (h >= 1) {
		while (i >= h && j >= 1)
			if (a[i] == a[j]) --i, --j;
			else i = m, j = --k;
		jump[h--] = k;
	}

	// search for word a in text b
	int occurs = 0;
	k = m;
	while (k <= n) {
		int i = m, j = k;
		while (i >= 1 && a[i] == b[j]) 
			--i, --j;   
		if (i < 1) ++occurs;
		if (i == m) k += 1;
		else k += m - jump[i+1];
	}
	return occurs;
}  