#include <stdio.h>
#include "mergesort.h"
#include "general_sort.h"
#include "randarray.h"
#include "quicksort.h"
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "../linkedLists/linked_list.h"
#include <unistd.h>  // Para usar usleep()
#include "heapsort.h"
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
	int arr[N];
	unsigned long long int count = 0ULL; // For fun

	// ===========================> array part
	printf("\n");
	printf("Array part\n\n");

	// For fun
	printf("Valor máximo de unsigned long long int: %llu\n\n", ULLONG_MAX);

	// Loop to find separated
	int is_it = 0; // As in "is it separated?"
	while (is_it == 0 || is_it == n-1 || is_it == -1) // Most common & obvious conditions. I don't want them.
	{
		// Random array size
		n = randInt(50,0);

		// Generates a random array
		randomArray(arr, n, 200, 100); 

		// Is it, though?
		is_it = is_separated(arr, 0, n); 

        // Prints count of loops
		printf("\rCount = %llu", count);

		// Counts & flush
		count++;
		fflush(stdout);

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