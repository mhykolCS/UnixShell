#include "functions.h"
#include <stdlib.h>

void get(struct data* userInput) {

	FILE *fileObj;
	int fileLines = 0;
	int printedLines = 0;
	char numberOfLines[100] = {'\0'};
	char file[50] = {'\0'};
	char systemCall[100] = {'\0'};
	char wait;
	char temp[10] = {'\0'};

	userInput->remainder = strtok(NULL, " \n");
	strcpy(file, userInput->remainder);
	strcpy(systemCall, "sed -n '$=' ");
	strcat(systemCall, file);

	fileObj = popen(systemCall, "r");

	fgets(numberOfLines, sizeof(numberOfLines), fileObj);

	if(!(strcmp(numberOfLines, "\0"))){
		return;
	}
	fileLines = atoi(numberOfLines);

	for(printedLines = 0; printedLines <= fileLines; printedLines+=40){
		sprintf(temp, "%d", printedLines+40);
		strcpy(systemCall, "head -");
		strcat(systemCall, temp);
		strcat(systemCall, " ");
		strcat(systemCall, file);
		strcat(systemCall, " | tail -40");
		system(systemCall);
		
		if(!(printedLines+40 <= fileLines)){
			printf("\n");
			break;
		}
		fgetc(stdin);

	}



	pclose(fileObj);

	//sed: can't read data.tx: No such file or directory\n

	//if(!(strcmp(numberOfLines, "sed: can't read data.tx: No such file or directory\n"))){
	//	printf("ERROR: Cannot find file %s\n", file);
	//}

	//printf("%s", numberOfLines);

	/*
	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}

	while (fgets(path, sizeof(path), fp) != NULL) {
		printf("%s", path);
	}

	pclose(fp);
	*/
	return;
}