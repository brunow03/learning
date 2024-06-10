#ifndef _GENERAL_SORT_H
#define _GENERAL_SORT_H

void selectionSort(int *v, int n);

void insertionsort (int v[], int n);

void rpinsertionsort(int v[], int p, int r);

void rSelectionSort(int v[], int n, int i);

void rinsertionsort(int v[], int n);

void printArray(int *v, int n);

int isincreasing(int v[], int n);

int binarySearch(int x, int n, int v[]);

void reversedInsertionSort(int v[], int n);

void swap(int *x, int *y);

int isDecreasing(int v[], int n);

void reversedSelectionSort(int *v, int n);

void stringSort(char (*)[20], int n);

void printArrayString(char (*)[20], int n);

int equal_arrays(int u[], int v[], int n);

#endif