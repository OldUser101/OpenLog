#include <ctype.h>

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