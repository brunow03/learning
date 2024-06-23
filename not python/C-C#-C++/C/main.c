#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>  // Para usar usleep()

#include "./include/binarytrees.h"
#include "./include/stringmatching.h"
#include "./include/mergesort.h"
#include "./include/general_sort.h"
#include "./include/radixsort.h"
#include "./include/quicksort.h"
#include "./include/heapsort.h"
#include "./include/linked_list.h"
#include "./include/randarray.h"
#include "./include/hashing.h"

#define N 1000

struct timespec start, end;
long long elapsed_ns;

int main(int argc, char const *argv[])
{
	printf("\n\033[1mProgram Starts!\033[0m\n");

	clock_gettime(CLOCK_MONOTONIC, &start);

	// Initializes random seed
	srand(time(NULL));

	// Core variables initialization
	int n;
	double epslon = 0.15; // tolerance
	int arr[N];
	unsigned long long int count = 0ULL; // For fun

	// ===========================> array part
	printf("\n");
	printf("Array part\n\n");

	// For fun
	printf("Valor máximo de unsigned long long int: %llu\n\n", ULLONG_MAX);

	// Loop to find separated
	n = 50;
	int is_it = 0; // As in "is it separated?"
	while (is_it < 2 || is_it > 48 
			/*is_it < ((float) n)*(0.5 - epslon) || is_it > ((float) n)*(0.5 + epslon)*/) 
			
			// Most common & obvious conditions. I don't want them.
	{
		// Random array size
		// n = randInt(20,0) + 30;

		// Generates a random array
		randomArray(arr, n, 200, 100);

		// Is it, though?
		is_it = is_separated(arr, 0, n); 

        // Prints count of loops
		// printf("\rCount = %llu", count);

		// Print count only every 1000 iterations
		if (count % 100000 == 0) {
			printf("\rCount = %llu", count);
			fflush(stdout);
		}

		// Counts & flush
		count++;
		// fflush(stdout);

		// Slow down the loop
        // usleep(50000);  // Sleep for 100,000 microseconds (0.1 seconds)
	}

	// Prints n
	printf("\nSize n = %d\n", n);

	// Prints the array
	printArray(arr, n);
	
	// Is separated
	printf("\nIs separated = ");
	printf("%d\n", is_it);

	// Positives and negatives
	positives_and_negatives(arr, n);
	printf("\nPositives_and_negatives \n");
	printArray(arr, n);

	// ===========================================================================================>	linked list part

	printf("\n===========================================================================================");
	printf("\n===========================================================================================\n");
	
	printf("\nLinked list part:\n\n");
	
	// Core variables initialization
	cell *lst, *lst_odd;

	// Gets a random list size n < 50
	n = randInt(50,0);

	// Prints n
	printf("Size = %d\n", n);

	//  Creates a linked list
	lst = initializeLL();

	// Fills it with n random elements
	fillupLL(lst, n);

	// Prints the list
	printlist(lst);
	printf("\n");

	// Even-odd linked lists. OG is even
	lst_odd = initializeLL();
	even_odd_linked_list(lst, lst_odd);
	printf("Even list\n");
	printlist(lst);
	printf("\nOdd list\n");
	printlist(lst_odd);

	// ===========================================================================================>	Quicksort part

	printf("\n===========================================================================================");
	printf("\n===========================================================================================\n");
	
	/*

	printf("\nPartition part:\n\n");
	int vector[] = {33,22,55,33,44,22,99,66,55,11,88,77,33,88,66,66};
	printArray(vector, 16);
	printf("j = %d\n", partition(vector, 0, 15));
	printf("After partition:\n");
	printArray(vector, 16);

	
	// For recursive partition
	printf("\nRecursive Partition part:\n\n");
	int rvector[] = {33,22,55,33,44,22,99,66,55,11,88,77,33,88,66,66};
	printArray(rvector, 16);
	printf("j = %d\n", rpartition(rvector, 0, 15, 0));
	printf("After recursive partition:\n");
	printArray(rvector, 16);

	printf("\nAre they equal: %d\n", equal_arrays(vector, rvector, 16));

	*/

	printf("\nQuicksort part:\n\n");
	int vector[] = {77,55,33,99};
	printArray(vector, 4);
	quicksort(vector, 0, 3);
	printf("After sort:\n");
	printArray(vector, 4);

	printf("\n");
	printf("\n");
	int teste[15];
	printf("%d\n", (int) sizeof(teste) / (int) sizeof(int));

	// ===========================================================================================>	Heapsort part

	printf("\n===========================================================================================");
	printf("\n===========================================================================================\n");

	printf("\nHeapsort part:\n\n");

	int heap_vector[] = {84, 974, 772, 756, 553, 397, 654, 106, 821, 796};

	n = 9;
	heap_vector[0] = 0;
	printArray(heap_vector, n);
	printf("Is it heap: %d\n\n", isheap(heap_vector, n));
	buildheap(heap_vector, n);
	printArray(heap_vector, n);
	printf("Is it heap now? %d\n\n", isheap(heap_vector, n));

	int new_heap_vector[] = {0, 690, 608, -995, -495, -773, 774, -237, 754, -474};
	printf("Heap sorting:\n");
	heapsort(new_heap_vector, n);
	printArray(new_heap_vector, n);

	// ===========================================================================================>	Radix sorting part

	printf("\n===========================================================================================");
	printf("\n===========================================================================================\n");
	printf("\n");

	int radix_n;
	radix_n = randInt(50,0);
	int radix_vector[radix_n];

	bin_rand_array(radix_vector, radix_n);
	printf("Radix_n = %d\n", radix_n);
	printArray(radix_vector, radix_n);
	organize_bin(radix_vector, radix_n);
	printArray(radix_vector, radix_n);

	// DNA
	printf("\n");
	radix_n = randInt(50,0);
	char dna_vector[radix_n];
	DNA_rand_array(dna_vector, radix_n);
	printf("Array size = %d\n", radix_n);
	printcArray(dna_vector, radix_n);

	// transforming in an int array
	int *dna_vector_int;
	dna_vector_int = dna_to_int(dna_vector, radix_n);
	printArray(dna_vector_int, radix_n);

	countingsort(dna_vector_int, radix_n, 4);
	printArray(dna_vector_int, radix_n);

	// ===========================================================================================>	Hashing part
	
	printf("\n===========================================================================================");
	printf("\n===========================================================================================\n");
	printf("\n");

	printf("Hashing part\n");
	int Num;
	int R = 9999;
	char * file;

	// 1K
	file = "./data/randInt1k.txt";
	Num = 1000;
	printf("\n%d", Num);
	direct_addressing(Num,R,file);

	// 10K
	file = "./data/randInt10k.txt";
	Num = 10000;
	printf("\n%d", Num);
	direct_addressing(Num,R,file);

	// 100K
	file = "./data/randInt100k.txt";
	Num = 100000;
	printf("\n%d", Num);
	direct_addressing(Num,R,file);

	// 1M
	file = "./data/randInt1M.txt";
	Num = 1000000;
	printf("\n%d", Num);
	direct_addressing(Num,R,file);

	// ===========================================================================================>	Biinary Tree part
	
	printf("\n===========================================================================================");
	printf("\n===========================================================================================\n");
	printf("\n");

	printf("Binary tree part\n");
	printf("\n");

	tree myTree = initializeBinaryTree();

	initializeBinaryTree();
	leftrootright (myTree);

	free(myTree);

	// ===========================================================================================>	

	printf("\n\033[1mProgram complete!\033[0m\n");
	printf("\a");
	printf("\n");

	clock_gettime(CLOCK_MONOTONIC, &end);

	elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL +
                 (end.tv_nsec - start.tv_nsec);

    printf("Time taken: %lld nanoseconds\n", elapsed_ns);

	return 0;
}