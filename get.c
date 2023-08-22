#include "functions.h"
#include <stdlib.h>

void get(struct data* userInput) {

	FILE *fileObj;
	int words = 1;
	int fileLines = 0;
	int printedLines = 0;
	char numberOfLines[100] = {'\0'};
	char file[50] = {'\0'};
	char systemCall[100] = {'\0'};
	char temp[10] = {'\0'};

	for (int i = 0; i < strlen(userInput->wholeInput); i++) { // calculates the amount of numbers/words
		if (userInput->wholeInput[i] == ' ') {
			words++;
		}
	}

	if(words == 1){ //Error Handling
		printf("ERROR: Please supply a filename\n");
		return;
	}

	userInput->remainder = strtok(NULL, " \n"); //cycles to the next word token
	strcpy(file, userInput->remainder); // generates a bash prompt
	strcpy(systemCall, "sed -n '$=' ");
	strcat(systemCall, file);

	fileObj = popen(systemCall, "r"); //assigns filedata to an object

	fgets(numberOfLines, sizeof(numberOfLines), fileObj); //writes fileobj data into numberoflines

	if(!(strcmp(numberOfLines, "\0"))){ //Error handling
		return;
	}

	fileLines = atoi(numberOfLines); //int conversion

	for(printedLines = 0; printedLines <= fileLines; printedLines+=40){ //generates a bash prompt
		sprintf(temp, "%d", printedLines+40);
		strcpy(systemCall, "head -");
		strcat(systemCall, temp);
		strcat(systemCall, " ");
		strcat(systemCall, file);
		strcat(systemCall, " | tail -40");
		system(systemCall);
		
		if(!(printedLines+40 <= fileLines)){ //detects EOF
			printf("\n");
			break;
		}
		fgetc(stdin);  //waits for character input and flushes stdin file ptr
		fflush(stdin);

	}

	pclose(fileObj); // removes filecache and deallocates memory

	return;
}