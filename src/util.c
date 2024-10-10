// This file contains several utility functions that are used throughout the program

#include <ctype.h>
#include <stdio.h>

#include "util.h"

// Converts a string to uppercase
void strupper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

// Returns a value indicating whether a file can be opened in a given mode
int faccess(char* fname, char* mode)
{
	FILE* f;
	f = fopen(fname, mode);
	if (!f)
	{
		return 0;
	}
	fclose(f);
	return 1;
}