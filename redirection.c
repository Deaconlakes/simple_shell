#include "newheader.h"
/**
* Method used to manage I/O redirection
*/ 
void fileIO(char * args[], char* inputFile, char* outputFile, int option){
	pid_t pid = 5; 
	int err = -1;
char cdir[1024];	
	int fileDescriptor;
	
	if((pid=fork())==-1){
		printf("Child process could not be created\n");
		return;
	}
	if(pid==0){
		if (option == 0){
			fileDescriptor = open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600); 
			dup2(fileDescriptor, STDOUT_FILENO); 
			close(fileDescriptor);
		}else if (option == 1){
			fileDescriptor = open(inputFile, O_RDONLY, 0600);  
			dup2(fileDescriptor, STDIN_FILENO);
			close(fileDescriptor);
			fileDescriptor = open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
			dup2(fileDescriptor, STDOUT_FILENO);
			close(fileDescriptor);		 
		}
		 
		setenv("parent",getcwd(cdir, 1024),1);
		
		if (execvp(args[0],args)==err){
			printf("err");
			kill(getpid(),SIGTERM);
		}		 
	}
	waitpid(pid,NULL,0);
}
