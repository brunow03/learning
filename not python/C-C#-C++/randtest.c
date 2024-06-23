#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <float.h>

int main(){
	srand(time(NULL));
	printf("RAND_MAX: %d\n", RAND_MAX);
	printf("INT_MAX: %d\n", INT_MAX);
	for(int i = 0; i < 100; ++i)
		printf("%.17f\n", ((double) rand()) / ((double) RAND_MAX + 1.0) );
	return 0;
}
