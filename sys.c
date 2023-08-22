#include "functions.h"
#include <sys/utsname.h>
#include <stdlib.h>


void sys(void) {

	struct utsname osInfo;
	uname(&osInfo);

	printf("Operating System:  %s\n", osInfo.sysname);
    printf("Operating System Version:  %s\n", osInfo.version);
	system("cat /proc/cpuinfo | grep \"model name\" | head -1"); //piping output from cat into grep and printing the first line

	return;
}