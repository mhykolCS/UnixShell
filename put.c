#include "functions.h"
#include <stdlib.h>
#include <dirent.h>

void put(struct data* userInput) {

	DIR* directory;
	size_t words = 1;
	int force = 0;
	int fileError = 0;
	char systemCall[100] = { '\0' };
	char newDir[100] = { '\0' };
	int stringDirLocation = 1;
	int stringFileLocation = 2;


	for (int i = 0; i < strlen(userInput->wholeInput); i++) { // calculates the amount of words
		if (userInput->wholeInput[i] == ' ') {
			words++;
		}
	}

	if (words <= 2) {
		printf("Error: Please specify a directory name and a filename\n");
		return;
	}

	char** stringTable = malloc(sizeof(stringTable) * words); //allocates a dynamic 2d array and assigns each word to a row
	for (int i = 0; i < words; i++) {
		stringTable[i] = malloc(sizeof(char) * 50);
		strcpy(stringTable[i], userInput->remainder); // assign word into array
		if (!(strcmp(stringTable[i], "-f"))) {  //looks for flag location. if at the start of input, increase relevant locations by one
			force = 1;
			if (i == 1) {
				stringDirLocation = 2;
				stringFileLocation = 3;
			}
		}
		userInput->remainder = strtok(NULL, " \n"); //cycle to next word
	}

	if(force){
		strcat(systemCall, "mkdir -p ");
	}else{
		directory = opendir(stringTable[stringDirLocation]); //error handling
		if(directory != NULL){
			printf("ERROR: Directory already exists, perhaps use the -f [force] flag?\n");
			return;
		}
		strcat(systemCall, "mkdir "); //bash prompt generation
	}
	
	strcat(systemCall, stringTable[stringDirLocation]);
	system(systemCall);

	for (int i = stringFileLocation; i < words; i++) {
		if (!(strcmp(stringTable[i], "-f"))) { //ignore flag prompt in file copying
			continue;
		}

		strcpy(newDir, stringTable[stringDirLocation]); //bash prompt generation
		strcat(newDir, "/");
		strcat(newDir, stringTable[i]);
		fileError = rename(stringTable[i], newDir);

		if (fileError) { //error handling
			printf("ERROR: Could not copy %s to %s\n", stringTable[i], stringTable[stringDirLocation]);
		}else{
			printf("Copied %s to %s\n", stringTable[i], stringTable[stringDirLocation]);
		}
	}


	free(stringTable);
	return;
	
}