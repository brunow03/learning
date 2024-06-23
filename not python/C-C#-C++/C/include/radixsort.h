#ifndef RADIXSORT_H
#define RADIXSORT_H

typedef unsigned char byte;
typedef struct {
	double x, y;
} point;

void organize_bin(int v[], int n);
void organize_bin2(int v[], int n);
void create_DNA(char c[], int n);
void organize_int_DNA(int v[], int n);
void countingsort (int *v, int n, int R);
void digitalsort (byte **v, int n, int W, int R);
// void array_of_struct(point v[], int n);

#endif // RADIXSORT_H
