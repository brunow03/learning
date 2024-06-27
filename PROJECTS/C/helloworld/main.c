#include <stdio.h>
#include <string.h>
#include "./include/helloworld.h"

int main(int argc, char const *argv[])
{
	char arg[20];
	// system("gnome-terminal");
	display_help();
	while(1) {
		scanf("%20s", arg);
		if(!strcmp(arg, "--help")) {
			display_help();
		}
		else {
			print_greetings(arg);
		};
	}

	printf("\n");
	return 0;
}