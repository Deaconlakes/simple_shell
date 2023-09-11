#include "newheader.h"

/**
 * Method to change directory
 */
int changedir(char* myargs[])
{
	if (myargs[1] == NULL) {
		chdir(getenv("HOME")); 
		return 1;
	}
	else{ 
		if (chdir(myargs[1]) == -1) {
			write(1, myargs[1], strlen(myargs[1]));
			write(1, ",does not exist", 16);
            return -1;
		}
	}
	return (0);
}
