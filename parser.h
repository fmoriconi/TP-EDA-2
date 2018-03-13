#ifndef parescallback


#include<string.h>
#include "header.h"

typedef int(*pCallback) (char * key, char * value, void * userdata);

char* strlower(char str[]);

int parseCallback(char *key, char *value, void *userData);

#endif // !parescallback