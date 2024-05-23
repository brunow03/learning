#ifndef STACKOFCHARS_H
#define STACKOFCHARS_H

#define N 10

int t;
char stack[N];

void createstack ();
char pop (void);
void push (char y);
int isemptystack (void);
int isfullstack (void);
void freestack(void);
int wellformed (char s[]);
char *infixToPostfix (char *inf);

#endif