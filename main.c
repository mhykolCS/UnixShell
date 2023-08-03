#include <stdio.h>
#include <time.h>

struct data {
	char wholeInput[100];
	char firstWord[100];
	char remainder[100];
};

void calc() {
	return;
}

void shellTime() {
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



void dataParser(struct data* userInput) {


	if (strchr(userInput->wholeInput, ' ') != NULL) { //detects if line has a space or now [one or (two or more) words]
		for (int i = 0, j = 0; i < strlen(userInput->wholeInput); i++, j++) { // splits string into first word, and remainder
			if (userInput->wholeInput[i] != ' ') {
				userInput->firstWord[j] = userInput->wholeInput[i]; //first word iteration
			}
			else {
				userInput->firstWord[j] = '\n';
				userInput->firstWord[j + 1] = '\0';
				i++;
				for (j = 0; i < strlen(userInput->wholeInput); i++, j++) {
					userInput->remainder[j] = userInput->wholeInput[i]; //remainder iteration
				}
				userInput->remainder[j] = '\n';
				userInput->remainder[j + 1] = '\0';
				break;
			}
		}
	}
	else {
		strcpy(userInput->firstWord, userInput->wholeInput); //if one word, strcpy
		userInput->remainder[0] = '\0'; // null end the string so strlen = 0
	}

	return;
}


void functionTable(struct data* userInput) {

	if (!(strcmp(userInput->firstWord, "calc\n"))) {
		if (strlen(userInput->remainder) == 0) { //checks that a remainder was parsed
			printf("Command \"calc\" needs an expression\n\"calc + 3 4 3\"\n");
			return;
		}
		calc();
	}
	else if (!(strcmp(userInput->firstWord, "time\n"))) {
		shellTime();
	}
	else if (!(strcmp(userInput->firstWord, "path\n"))) {
		path();
	}
	else if (!(strcmp(userInput->firstWord, "sys\n"))) {
		sys();
	}
	else if (!(strcmp(userInput->firstWord, "put\n"))) {
		if (strlen(userInput->remainder) == 0) {
			printf("Command \"put\" needs a directory name and filename\n\"put file.txt folder\"\n");
			return;
		}
		put();
	}
	else if (!(strcmp(userInput->firstWord, "get\n"))) {
		if (strlen(userInput->remainder) == 0) {
			printf("Command \"get\" needs a filename\n\"get file.txt\"\n");
			return;
		}
		get();
	}
	else if (!(strcmp(userInput->firstWord, "quit\n"))) {
		return;
	}
	else {
		printf("Unknown command\n");
	}

	return;
}


void test(struct data* userInput) {

	printf("%s", userInput->wholeInput);

	fgets(userInput->remainder, sizeof(userInput->remainder), stdin);
	return;

}


int main(void) {

	struct data userInput = (struct data){ .firstWord[0] = '\0', .wholeInput[0] = '\0', .remainder[0] = '\0' };

	do {
		printf("$ ");

		fgets(userInput.wholeInput, sizeof(userInput.wholeInput), stdin); //grabs whole line from user

		dataParser(&userInput);

		functionTable(&userInput);

	} while (strcmp(userInput.firstWord, "quit\n"));



	return(0);
}