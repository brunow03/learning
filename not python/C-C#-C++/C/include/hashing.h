#ifndef HASHING_H
#define HASHING_H

typedef struct hrecord hcell;
struct hrecord {
	int key, occur; 
	hcell *next;
};

void direct_addressing(int N, int R, char * file);
void count (int k);

#endif // HASHING_H
