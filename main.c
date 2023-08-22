#include "functions.h"


void dataParser(struct data* userInput){

	strcpy(userInput->firstWord, userInput->wholeInput);
	userInput->remainder = strtok(userInput->firstWord, " \n");

	return;
}


void functionTable(struct data* userInput) {

	if (!(strcmp(userInput->firstWord, "calc\0"))) {
		calc(userInput);
	}
	else if (!(strcmp(userInput->firstWord, "time\0"))) {
		shellTime();
	}
	else if (!(strcmp(userInput->firstWord, "path\0"))) {
		path();
	}
	else if (!(strcmp(userInput->firstWord, "sys\0"))) {
		sys();
	}
	else if (!(strcmp(userInput->firstWord, "put\0"))) {
		put(userInput);
	}
	else if (!(strcmp(userInput->firstWord, "get\0"))) {
		get(userInput);
	}
	else if (!(strcmp(userInput->firstWord, "quit\0"))) {
		return;
	}
	else {
		printf("ERROR: Unknown command\n");
	}

	return;
}

 

int main(void) {

	struct data userInput = (struct data){ .firstWord[0] = '\0', .wholeInput[0] = '\0', .remainder = NULL};
 
	do {
		printf("$ ");

		fgets(userInput.wholeInput, sizeof(userInput.wholeInput), stdin);

		dataParser(&userInput); //converts wholeimput into first word and remainder[token]

		functionTable(&userInput); // table for different function calls

	} while (strcmp(userInput.firstWord, "quit\0")); // while firstword does not equal



	return(0);
}