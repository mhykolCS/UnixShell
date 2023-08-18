#include "functions.h"
#include <time.h>

void shellTime(void) {

	time_t epochTime;
	struct tm currentTime;
	char asciiCurrentTime[50];

	time(&epochTime);
	localtime_r(&epochTime, &currentTime);
	asctime_r(&currentTime, asciiCurrentTime);

	printf("The current time and date is: %s", asciiCurrentTime);


	return;
}