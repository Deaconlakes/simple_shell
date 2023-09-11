#include "newheader.h"

/**
* Main method of our shell
*/

extern char **environ;
int main() {
	char *input = NULL;
	char * array_t[100]; 
	char *del = " \n\t";
	int x = 1;
	size_t len;
	shellpmt();

	while(1)
	{
		len = (sizeof(char) * (strlen(input)+1));
		
		memset (input, '\0', len);
		input = (char *)malloc(sizeof(char) * len);

		getline(&input, &len, stdin);
	
		if((array_t[0] = strtok(input, del)) == NULL)
		{ 
			free (input);
			continue;
		}
		
		while((array_t[x] = strtok(NULL, del)) != NULL)
			x++;
		
		handle(array_t);
		free (input);
		
	}          

	exit(0);
}
