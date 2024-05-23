#include <stdio.h>

int main(int argc, char const *argv[])
{
	long nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;

	printf("%ld\n", nc);
	return 0;
}