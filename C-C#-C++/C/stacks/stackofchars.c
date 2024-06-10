#include "stackofchars.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void createstack (void){
	t = 0;
}

char pop (void){
	return stack[--t];
}

void push (char y){
	stack[t++] = y;
}

int isemptystack (void){
	return t <= 0;
}

int isfullstack (void){
	return t > N;
}

////////////////////////////////////////////////////////////////////////////////////
void freestack (void){
	t = 0;
}
////////////////////////////////////////////////////////////////////////////////////

int wellformed (char s[]) 
{
	createstack ();
	for (int i = 0; s[i] != '\0'; ++i) {
		char c;
    	switch (s[i]) {
        	case ')':	if (isemptystack ()) return 0;
						c = pop ();
						if (c != '(') return 0;
						break;
         	case ']':	if (isemptystack ()) return 0;
						c = pop ();
						if (c != '[') return 0;
						break;
			default:	push (s[i]);
		}
	}
	return isemptystack ();
}

////////////////////////////////////////////////////////////////////////////////////

char *infixToPostfix (char *inf) {
	int n = strlen (inf);
	char *post; 
	post = malloc ((n+1) * sizeof (char));
	createstack ();
	push (inf[0]);       // push '('

	int j = 0;
	for (int i = 1; inf[i] != '\0'; ++i) {
		switch (inf[i]) {
			char x;
			case '(':	push (inf[i]);
						break;
			case ')':	x = pop ();
						while (x != '(') {
							post[j++] = x;
							x = pop ();
						}
						break;
			case '+':
			case '-':	x = pop ();
						while (x != '(') {
							post[j++] = x;
							x = pop ();
						}
						push (x);
						push (inf[i])
						break;
			case '*':
			case '/':	x = pop ();
						while (x != '(' && x != '+' && x != '-') {
							post[j++] = x;
							x = pop ();
						}
						push (x);
						push (inf[i]);
						break;
			default:	post[j++] = inf[i];
		}
	}
	post[j] = '\0';      
	return post;
}