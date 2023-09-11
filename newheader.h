#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void shellpmt(void);
void welcome();
int handle(char * myargs[]);
int manageEnviron(char * args[], int option);
void pipeHandler(char * args[]);
void fileIO(char * args[], char* inputFile, char* outputFile, int option);
void signalHandler_child();
int manageEnviron(char *args[], int option);
void prog(char* myargs[], int background);
int changedir(char* myargs[]);
#endif
