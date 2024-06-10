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
#define N 10

struct timespec start, end;
long long elapsed_ns;

int main(int argc, char const *argv[])
{
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
		n = randInt(50,0,1);

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
	n = randInt(50,0,1);

	// Prints it
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
	
	int heap_vector[] = {1, 4, 6, 7, 11, 16, 17, 21, 22, 26, 27, 29, 31, 37, 44, 53, 55, 56, 60, 63, 64, 68, 70, 78, 81, 84, 87, 
	88, 89, 94, 97, 102, 105, 112, 118, 120, 121, 126, 127, 129, 133, 141, 146, 147, 151, 152, 154, 158, 165, 168, 170, 175, 176, 
	177, 180, 186, 187, 189, 192, 195, 201, 206, 208, 211, 212, 213, 222, 230, 231, 234, 236, 237, 242, 243, 244, 247, 249, 250, 
	251, 259, 260, 261, 264, 270, 271, 272, 274, 281, 287, 289, 294, 303, 304, 311, 319, 323, 325, 326, 328, 329, 333, 335, 341, 
	344, 355, 356, 360, 364, 365, 366, 367, 368, 372, 373, 376, 377, 383, 384, 385, 390, 391, 392, 393, 400, 403, 408, 410, 423, 
	425, 426, 433, 434, 439, 442, 447, 450, 453, 457, 458, 463, 464, 465, 469, 476, 479, 482, 492, 495, 496, 500, 503, 506, 507, 
	508, 510, 516, 524, 526, 527, 528, 533, 538, 545, 551, 556, 558, 560, 562, 564, 565, 571, 575, 577, 583, 585, 588, 590, 593, 
	597, 607, 610, 611, 617, 621, 628, 630, 631, 633, 636, 638, 641, 642, 647, 649, 656, 663, 670, 672, 673, 680, 684, 685, 688, 
	693, 694, 695, 697, 699, 704, 706, 713, 715, 718, 722, 732, 733, 737, 738, 739, 740, 741, 747, 748, 752, 753, 757, 764, 767, 
	769, 770, 771, 776, 781, 783, 785, 788, 789, 793, 801, 803, 805, 812, 814, 822, 826, 831, 833, 834, 842, 844, 847, 851, 852, 
	858, 862, 863, 864, 867, 868, 869, 871, 873, 878, 881, 883, 888, 891, 895, 897, 900, 902, 905, 906, 911, 915, 917, 922, 923, 
	925, 930, 935, 939, 944, 946, 947, 958, 962, 964, 967, 972, 973, 976, 978, 980, 982, 985, 989, 991, 993, 1000};

	n = 300;
	printArray(heap_vector, n);
	printf("Is it heap: %d\n\n", isheap(heap_vector, n));
	buildheap(heap_vector, n);
	printArray(heap_vector, n);
	printf("Is it heap now? %d\n\n", isheap(heap_vector, n));

	printf("Heap sprting:\n");
	heapsort(heap_vector, n);
	printArray(heap_vector, n);

	printf("\n\033[1mProgram complete!\033[0m\n");
	printf("\a");
	printf("\n");






	clock_gettime(CLOCK_MONOTONIC, &end);

	elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL +
                 (end.tv_nsec - start.tv_nsec);

    printf("Time taken: %lld nanoseconds\n", elapsed_ns);

	return 0;
}