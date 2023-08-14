#include "functions.h"
#include <time.h>

void shellTime(void) {

	time_t epochTime;
	struct tm currentTime;
	char asciiCurrentTime[50];

	time(&epochTime);
	localtime_s(&currentTime, &epochTime);
	asctime_s(asciiCurrentTime, sizeof(asciiCurrentTime), &currentTime);

	printf("The current time and date is: %s", asciiCurrentTime);


	return;
}