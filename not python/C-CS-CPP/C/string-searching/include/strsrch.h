#ifndef STRSRCH_H
#define STRSRCH_H

typedef unsigned char byte;
int naive (byte a[], int m, byte b[], int n);
int consecutive_spaces(int m, byte b[], int n);
int boyermoore1 (byte a[], int m, byte b[], int n);
int boyermoore2 (byte a[], int m, byte b[], int n);

#endif // STRSRCH_H
