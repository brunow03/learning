/*
Array implementation of the josephus problem

*/

#include <stdio.h>
#define SENTINEL -1

int main()
{
    int M, N, i, count = 0, steps, arr[100];
    scanf("%d %d", &M, &N);
    for (i=0; i < N; i++){ arr[i] = i+1; printf("%d ", arr[i]); }
    printf("\n");
    arr[i] = SENTINEL;
    i--; // i = N-1
    while (count < N) {
        for (steps = 0; steps < M; steps++) {
            i++;
            if (arr[i] == SENTINEL) {
    	       i = 0; 
            }
            while (arr[i] == 0) {
                i++;
                if (arr[i] == SENTINEL) i = 0;
            }
        }
        while (arr[i] == 0) {
            i++;
            if (arr[i] == SENTINEL) i = 0;
        }
        printf("%d ", arr[i]);
        arr[i] = 0;
        count++;
    }
    return 0;
}