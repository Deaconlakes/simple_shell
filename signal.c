#include "newheader.h"

/**
 * signal handler for SIGCHLD
 */
void signalHandler_child(){
	/* Wait for all dead processes.
	 * We use a non-blocking call (WNOHANG) to be sure this signal handler will not
	 * block if a child was cleaned up in another part of the program. */
	while (waitpid(-1, NULL, WNOHANG) > 0) {
	}
	printf("\n");
}
/**
 * Signal handler for SIGINT
 */
void signalHandler_int(){
	pid_t pid = 5;
	if (kill(pid,SIGTERM) == 0){
		printf("\nProcess %d received a SIGINT signal\n",pid);
	}else{
		printf("\n");
	}
}
