/*time_console.c*/
#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	time_t timer;
	time(&timer);

	printf("Local time is: %s", ctime(&timer));
	return 0;
}