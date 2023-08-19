#include "functions.h"
#include <stdlib.h>
#include <ctype.h>

void add(char** stringTable, size_t words){
	
	double temp = 0;
	double total = 0;

	for(int i = 2; i < words; i++){
		temp = atof(stringTable[i]);
		total += temp;
	}

	printf("%.2f\n", total);

	return;
}

void subtract(char** stringTable, size_t words){
	
	double temp = 0;
	double total = 0;
	int start = 2;
	int boolNumber = 1;

	for(int i = 2; i < words; i++){ // detects which row entry the first number is at
		boolNumber = 1;
		for(int j = 0; stringTable[i][j] != '\0' && boolNumber; j++){
			if(!(isdigit(stringTable[i][j]))){
				boolNumber = 0;
			}
		}

		if(!(boolNumber)){
			start++;
			continue;
		}else{
			break;
		}
	}

	total = atof(stringTable[start]); // assigns total to first number so subtraction doesn't start from 0
	start++;

	for(int i = start; i < words; i++){
		temp = atof(stringTable[i]);
		total -= temp;
	}

	printf("%.2f\n", total);

	return;
}


void calc(struct data *userInput) {

	size_t words = 1;
	for(int i = 0; i < strlen(userInput->wholeInput); i++){ // calculates the amount of numbers/words
		if(userInput->wholeInput[i] == ' '){
			words++;
		}
	}

	if(words <= 2){
		printf("0\n");
		return;
	}

	char** stringTable = malloc(sizeof(stringTable) * words); //allocates a dynamic 2d array and assigns each word to a row
	for(int i = 0; i < words; i++){
		stringTable[i] = malloc(sizeof(char) * 20);
		strcpy(stringTable[i], userInput->remainder);
		userInput->remainder = strtok(NULL, " \n");
	}
	
	switch(stringTable[1][0]){
		case '+':
			add(stringTable, words);
			break;

		case '-':
			subtract(stringTable, words);
			break;

		default:
			printf("Unknown Expression Character\n");
			break;
	}
	

	free(stringTable);
	return;
}