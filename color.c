#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "color.h"

// Define color macros for Windows systems
#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

void setTextColor(int color) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void putstr(const char* str, unsigned char color)
{
	setTextColor(color);
	printf(str);
	setTextColor(COLOR_DEFAULT);
}

// Define color macros for Unix systems
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)

void setTextColor(const char* color) 
{
	printf("%s", color);
}

void putstr(const char* str, unsigned char color)
{
	setTextColor(color);
	printf(str);
	setTextColor(COLOR_DEFAULT);
}

// Define color macros for DOS systems
#elif defined(MSDOS) || defined(_MSDOS) || defined(__MSDOS__) || defined(_DOS) || defined(__DOS__)

void setTextColor(unsigned char color, char c)
{
	asm
	{
		mov ah, 0x09
		mov al, c
		mov bh, 0x00
		mov bl, color
		mov cx, 1
		int 0x10
		mov ah, 0x03
		mov bh, 0x00
		int 0x10
		inc dl
		mov ah, 0x02
		int 0x10
	}       
}

void putstr(const char* str, unsigned char color)
{
	while (*str)
	{
		setTextColor(color, *str);
		str++;
	}
}

#else
#error "Unsupported operating system."
#endif

void printfc(unsigned char color, const char* format, ...)
{
	va_list args;
	char* str;
	va_start(args, format);
	str = (char*)malloc(strlen(format));
	vsprintf(str, format, args);
	putstr(str, color);
	va_end(args);
}

// Displays a status message with a given status.
void printStatus(const char* msg, int code)
{
	char textCol;
	const char* errStr;
	
	// Set the text color and text depending on the code
	switch (code)
	{
		case STATUS_INFO:
			textCol = COLOR_LBLUE;
			errStr = "INFO";
			break;
		case STATUS_WARNING:
			textCol = COLOR_LYELLOW;
			errStr = "WARN";
			break;
		case STATUS_ERROR:
			textCol = COLOR_LRED;
			errStr = "ERROR";
			break;
		default:
			textCol = COLOR_DEFAULT;
			break;
	}

	// Print the message like "[TEXT] :: MESSAGE"
	printf("	[");
	putstr(errStr, textCol);
	printf("] :: %s\n", msg);       
}