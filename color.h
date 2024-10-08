#ifndef _OLOG_COLOR
#define _OLOG_COLOR
#endif

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define STATUS_INFO 1
#define STATUS_WARNING 2
#define STATUS_ERROR 3

// Define color macros for Windows systems
#if defined(_WIN32) || defined(_WIN64)

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_AQUA 3
#define COLOR_RED 4
#define COLOR_PURPLE 5
#define COLOR_YELLOW 6
#define COLOR_LGRAY 7
#define COLOR_GRAY 8
#define COLOR_LBLUE 9
#define COLOR_LGREEN 10
#define COLOR_LAQUA 11
#define COLOR_LRED 12
#define COLOR_LPURPLE 13
#define COLOR_LYELLOW 14
#define COLOR_WHITE 15
#define COLOR_DEFAULT COLOR_LGRAY

void setTextColor(int color) ;
void putstr(const char* str, unsigned char color);

// Define color macros for Unix systems
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)

#define COLOR_BLACK "\033[0;30m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_AQUA "\033[0;36m"
#define COLOR_GRAY "\033[0;37m"
#define COLOR_LBLACK "\033[0;90m"
#define COLOR_LRED "\033[0;91m"
#define COLOR_LGREEN "\033[0;92m"
#define COLOR_LYELLOW "\033[0;93m"
#define COLOR_LBLUE "\033[0;94m"
#define COLOR_LPURPLE "\033[0;95m"
#define COLOR_LAQUA "\033[0;96m"
#define COLOR_WHITE "\033[0;97m"
#define COLOR_DEFAULT "\033[0m"

void setTextColor(const char* color);
void putstr(const char* str, unsigned char color);

// Define color macros for DOS systems
#elif defined(MSDOS) || defined(_MSDOS) || defined(__MSDOS__) || defined(_DOS) || defined(__DOS__)

#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_AQUA 3
#define COLOR_RED 4
#define COLOR_PURPLE 5
#define COLOR_BROWN 6
#define COLOR_LGRAY 7
#define COLOR_GRAY 8
#define COLOR_LBLUE 9
#define COLOR_LGREEN 10
#define COLOR_LAQUA 11
#define COLOR_LRED 12
#define COLOR_LPURPLE 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15
#define COLOR_DEFAULT COLOR_LGRAY
#define COLOR_LYELLOW COLOR_YELLOW

// Define inline assembly macros for DOS
#if defined(_MSC_VER)
#define asm __asm
#elif defined(__GNUC__) || defined(__DJGPP__)
#define asm __asm__
#elif defined(__BORLANDC__) || defined(__TURBOC__)
#define asm asm
#elif defined(__WATCOMC__)
#define asm __asm
#endif

void setTextColor(unsigned char color, char c);
void putstr(const char* str, unsigned char color);

#else
#error "Unsupported operating system."
#endif

void printfc(unsigned char color, const char* format, ...);

// Displays a status message with a given status.
void printStatus(const char* msg, int code);