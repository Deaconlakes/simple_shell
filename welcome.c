#include "newheader.h"
/**
 *	Displays a welcome
 */
void welcome(){
	char myname[1204] = "";
	gethostname(myname, sizeof(myname));
	if (myname != NULL)
	{
		write(1, "welcome/t", 8);
		write(1, myname, strlen(myname));
	}
	else {
		perror("enter a your name");
	}
}
