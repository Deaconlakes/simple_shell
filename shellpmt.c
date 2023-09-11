#include "newheader.h"

void shellpmt(void)
{
	char *prompt = "lestish=> ";
	char *input = NULL;
	ssize_t num_cha;
	size_t len;
	
	if (isatty(0))
		write(1, prompt, 10);

	if ((num_cha =(getline(&input, &len, stdin))) == 0)
        {
            write(1, "Goodbye", 7);
	    free(input);
            exit(0);
        }
}
