#include <stdio.h>

#include "openlog.h"
#include "color.h"
#include "help.h"

#define _VERSION "v0.1"

// Display usage information
void usage()
{
	printfc(COLOR_LYELLOW, "OpenLog");
	printf(" - A cross-platform universal logging library\n");
	printf("Copyright (C) 2024 Nathan Gill - Version %s\n", _VERSION);
	printfc(COLOR_LGREEN, "Usage");
	printf(": openlog <command> [options] ...\n");
	printf("Commands:\n");
	printf("	start	Starts the main logging process\n");
	printf("	stop	Stops the main logging process\n");
	printf("	init	Creates a new log for a process\n");
	printf("	raise	Raises an event in the log\n");
	printf("	help	Displays help on a given command\n");
	printfc(COLOR_LAQUA, "See 'openlog help <command>' for help on a specific command.\n");
	printfc(COLOR_LAQUA, "See 'openlog help openlog' for more information.\n");
}

// Converts a string to uppercase
void strupper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

// Returns an integer identifying the supplied command. openlog.h for definitions.
int getCommand(int argc, char* argv[])
{
	char* command;
	if (argc < 2) return COMMAND_ERROR;
	command = argv[1];
	command[strlen(argv[1])] = '\0';
	strupper(command);  // Make the string uppercase for comparision
	
	if (!strcmp(command, "HELP"))
		return COMMAND_HELP;
	else if (!strcmp(command, "RAISE"))
		return COMMAND_RAISE;
	else if (!strcmp(command, "INIT"))
		return COMMAND_INIT;
	else if (!strcmp(command, "STOP"))
		return COMMAND_STOP;
	else if (!strcmp(command, "START"))
		return COMMAND_START;
	return COMMAND_NONE;
}

// Main application entry point
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		usage();
		return 0;
	}
	// Show the command (TESTING)
	printf("Command: %i\n", getCommand(argc, argv));
	return 0;
}