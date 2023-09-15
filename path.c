#include "newheader.h"

int path()
{
	char *path;
	char *path_copy;
	char *dir;
	path = getenv("PATH");

    if (path == NULL) {
        return 0;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        return 0;  
    }

    dir = strtok(path_copy, ":");
    while (dir != NULL) {
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return 0; 
}
