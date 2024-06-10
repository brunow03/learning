#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "recursive.h"
#define N 10

int main(int argc, char const *argv[])
{
    int v[N];
    int n = N;
    clock_t start, end;
    double cpu_time_used;
    int m;

    srand((unsigned)time(NULL));
    int num = rand() % 10000;

    arrayGen(n, v);
    printArray(n, v);
    printf("rsumPositive: %d\n", rsumPositive(n, v));
    printf("maximo: %d\n", maximo(n, v));
    printf("ttt: %d\n", ttt(n,v));
    printf("rprodPositive: %d\n", rprodPositive(n,v));
    printf("sumDigits: %d %d\n", num, sumDigits(num));
    printf("rlg: %d\n", rlg(num));
    printf("f(%d,%d): %f\n", 50, 100, f(50,100));
    printf("XX(x,y): Segmentation fault (core dumped)\n"); // segmentation fault
    
    n = 10;
    start = clock();
    printf("rfibonacci(%d): %d\n", n, rfibonacci(n));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("rFibonacci execution time for n = %d: %f\n", n, cpu_time_used);

    m = 252; n = 105;
    printf("Euclides(%d,%d): %d\n", m, n, Euclides(m,n));
    printf("rEuclides(%d,%d): %d\n", m, n, Euclides(m,n));

    m = 5; n = 4;
    printf("Exponentiation(%d,%d): %d\n", m, n, exponentiation(m,n));

    return 0;
}