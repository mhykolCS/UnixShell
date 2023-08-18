#include <unistd.h>
#include "functions.h"


void path(void) {
	char dir[256] = {'\0'};

	getcwd(dir, 256*sizeof(char));

	printf("%s\n", dir);
	return;
}