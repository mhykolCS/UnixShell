#include <stdio.h>
#include <string.h>
#include <time.h>

struct data {
	char wholeInput[100];
	char firstWord[100];
	char *remainder;
};


void calc() {
	return;
}

void shellTime() {

	time_t rawTimeData;
	struct tm* currentTimeStructure;
	char currentTimeString[50];

	time(&rawTimeData); //epoch time
	localtime_s(&currentTimeStructure, &rawTimeData); //fills structure with curated time data
	asctime_s(currentTimeString, sizeof(currentTimeString), &currentTimeStructure); // converts structure to a string
	printf("\nCurrent time and date: %s", currentTimeString);

	return;
}

void path() {
	return;
}

void sys() {
	return;
}

void put() {
	return;
}

void get() {
	return;
}


void dataParser(struct data* userInput){

	strcpy_s(userInput->firstWord, sizeof(userInput->firstWord), userInput->wholeInput);
	strtok_s(userInput->firstWord, " \n", &userInput->remainder);

	return;
}


void functionTable(struct data* userInput) {

	if (!(strcmp(userInput->firstWord, "calc\0"))) {
		if (!(strcmp(userInput->remainder, ""))) { //checks that a remainder was parsed
			printf("Command \"calc\" needs an expression\n\"calc + 3 4 3\"\n");
			return;
		}
		calc();
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
		put();
	}
	else if (!(strcmp(userInput->firstWord, "get\0"))) {
		if (userInput->remainder == NULL) {
			printf("Command \"get\" needs a filename\n\"get file.txt\"\n");
			return;
		}
		get();
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