#include "recursive.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ao receber v e n >= 1, a função devolve
// o valor de um elemento máximo do
// vetor v[0..n-1].

int 
maximo (int n, int v[])
{ 
    if (n == 1)
        return v[0];
    else {
        int x;
        x = maximo (n-1, v);
        // x é o máximo de v[0..n-2] 
        if (x > v[n-1]) return x;
        else return v[n-1]; 
   }
}

int
rsumPositive(int n, int v[]){
    if (n <= 0) return 0; // Reached the end of the vay: return zero
    if (*v <= 0) return rsumPositive(n - 1, v + 1); // Non-positive number: skip it
    return rsumPositive(n - 1, v + 1) + *v;  // Add this number to the recursion result!
}


int
rprodPositive(int n, int v[]){
	if (n <= 0) return 1; // Reached the end of the vay: return zero
    if (*v <= 0) return rprodPositive(n-1, v+1); // Non-positive number: skip it
    return rprodPositive(n-1, v+1) * (*v);  // multiply this number to the recursion result!
}

void
printArray(int n, int v[]){
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

// generate array of random ints sized n

void
arrayGen(int n, int v[]){
	int i;
    srand( (unsigned)time(NULL) );
    for(i = 0; i < n ; i++)
        v[i] = rand()%20 - 10;
}

// sum of number >100 in an array

int 
ttt(int n, int x[]) {
   if (n == 0) return 0;
   if (x[n-1] > 100)  return x[n-1] + ttt(n-1, x);
   else  return ttt(n-1, x);
}

int
sumDigits (int n){
	if (n == 0) return 0;
	return n % 10 + sumDigits(n / 10);
}

// A função lg recebe um inteiro N > 0 
// e devolve o piso de log N, ou seja,
// o único inteiro i tal que
// 2^i <= N < 2^(i+1).

int lg (int N)
{  
	int i, n;
	i = 0;
	n = 1;
	while (n <= N/2) {
		n = 2 * n;
		i += 1;
	}
	return i;    
}

// versão recursiva

int
rlg (int N)
{
	if (N < 2) return 0;
	else return 1 + rlg(N/2);
}

double f (double x, double y) {
	return (x + y)/2;
}

int XX (int n) {
	if (n == 0) return 0;
	else return XX (n/3+1) + n;
}

int
rfibonacci(int n){
	if (n == 1) return 1;
	if (n == 0) return 0;
	return rfibonacci(n-1) + rfibonacci(n-2);
}

int 
Euclides (int m, int n) {
   int r;
   do {
      r = m % n; 
      m = n; 
      n = r;
   } while (r != 0);
   return m; 
}

int
rEuclides(int m, int n){
	if (m%n == 0) return n;
	return Euclides(n, m%n);
}

int 
exponentiation(int k, int n){
	if (n == 1) return k;
	return k * exponentiation(k,n-1);
}

// A função maxr4 devolve um elemento máximo
// do vetor v[p..r]. Ela supõe que p <= r. 
//
int 
maxr4 (int v[], int p, int r) {   
	int u, v; 
	int m = (p + r)/2; 
	if (p == r) return v[p];
	u = maxr4(v, p, m);
	v = maxr4(v, m+1, r);
	if (u > v) return u; 
	else return v;
}