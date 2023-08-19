#include "functions.h"


void dataParser(struct data* userInput){

	strcpy(userInput->firstWord, userInput->wholeInput);
	userInput->remainder = strtok(userInput->firstWord, " \n");

	return;
}


void functionTable(struct data* userInput) {

	if (!(strcmp(userInput->firstWord, "calc\0"))) {
		if (!(strcmp(userInput->remainder, ""))) { //checks that a remainder was parsed
			printf("Command \"calc\" needs an expression\n\"calc + 3 4 3\"\n");
			return;
		}
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
		if (userInput->remainder == NULL) {
			printf("Command \"put\" needs a directory name and filename\n\"put file.txt folder\"\n");
			return;
		}
		put(userInput);
	}
	else if (!(strcmp(userInput->firstWord, "get\0"))) {
		if (userInput->remainder == NULL) {
			printf("Command \"get\" needs a filename\n\"get file.txt\"\n");
			return;
		}
		get(userInput);
	}
	else if (!(strcmp(userInput->firstWord, "quit\0"))) {
		return;
	}
	else {
		printf("Unknown command\n");
	}

	return;
}



int main(void) {

	struct data userInput = (struct data){ .firstWord[0] = '\0', .wholeInput[0] = '\0', .remainder = NULL};
 
	do {
		printf("$ ");

		fgets(userInput.wholeInput, sizeof(userInput.wholeInput), stdin);

		dataParser(&userInput);

		functionTable(&userInput);

	} while (strcmp(userInput.firstWord, "quit\0"));



	return(0);
}