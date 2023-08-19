#include <stdio.h>
#include <string.h>

struct data {
	char wholeInput[100];
	char firstWord[100];
	char *remainder;
};


void shellTime(void);
void calc(struct data *userInput);
void path(void);
void sys(void);
void put(struct data *userInput);
void get(struct data *userInput);
