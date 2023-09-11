#include "newheader.h"

/**
* Method for launching a program. It can be run in the background
* or in the foreground
*/ 
void prog(char* myargs[], int background){	 
	 int err = -1;
	 pid_t pid;
	 char cdir[1024];
	 
	 if((pid=fork()) == -1){
		 printf("Child process could not be created\n");
		 return;
	 }
	if(pid==0){
		signal(SIGINT, SIG_IGN);
		
		setenv("parent",getcwd(cdir, 1024),1);	
		
		if (execvp(myargs[0], myargs)==err){
			printf("Command not found");
			kill(getpid(),SIGTERM);
		}
	 }

	 if (background == 0){
		 waitpid(pid,NULL,0);
	 }else{
		 printf("Process created with PID: %d\n",pid);
	 }
}
