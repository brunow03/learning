#include "../include/helloworld.h"
#include <stdio.h>
#include <string.h>

void display_help(void){
	printf("Ajuda:\n");
	printf("\'--help\' ou \'-h\': Mostra a opção de ajuda.\n");
	printf("\n");
	printf("Saudações:\n");
	printf("\'--pt\': Saudações em português.\n");
	printf("\'--en\': Saudações em inglês.\n");
	printf("\'--es\': Saudações em espanhol.\n");
	printf("\'--fr\': Saudações em francês.\n");
	printf("\'--it\': Saudações em italiano.\n");
	printf("\'--de\': Saudações em alemão.\n");
	printf("\'--jp\': Saudações em japonês.\n");
	printf("\'--ch\': Saudações em chinês tradicional.\n");
	printf("\'--ru\': Saudações em russo.\n");
	printf("\n");
}

static int
convert_arg(const char *arg){
	if(!strcmp(arg, "--pt")) {
		return 1;
	}
	else if(!strcmp(arg, "--en")) {
		return 2;
	}
	else if(!strcmp(arg, "--es")) {
		return 3;
	}
	else if (!strcmp(arg, "--fr")) {
		return 4;
	}
	else if (!strcmp(arg, "--it")) {
		return 5;
	}
	else if (!strcmp(arg, "--de")) {
		return 6;
	}
	else if (!strcmp(arg, "--jp")) {
		return 7;
	}
	else if (!strcmp(arg, "--ch")) {
		return 8;
	}
	else if (!strcmp(arg, "--ru")) {
		return 9;
	}
	else
		return -1;
}

void print_greetings(const char *arg){
	int argn = convert_arg(arg);
	switch (argn){
		case 1:
			printf("Olá, mundo!\n");
			break;
		case 2:
			printf("Hello, world!\n");
			break;
		case 3:
			printf("¡Hola, mundo!\n");
			break;
		case 4:
			printf("onjour, le monde!\n");
			break;
		case 5:
			printf("Ciao, mondo!\n");
			break;
		case 6:
			printf("Hallo, Welt!\n");
			break;
		case 7:
			printf("こんにちは、世界！\n");
			break;
		case 8:
			printf("你好，世界！\n");
			break;
		case 9:
			printf("Привет, мир!\n");
			break;
		default:
			printf("Invalid option.\n");
	}
}