#include <stdio.h>

#include "openlog.h"
#include "color.h"
#include "util.h"

void banner()
{
	printfc(COLOR_LYELLOW, "OpenLog");
	printf(" - A cross-platform universal logging library\n");
	printf("Copyright (C) 2024 Nathan Gill - Version %s\n", _VERSION);
}

// Display usage information
void usage()
{
	banner();
	printfc(COLOR_LGREEN, "Usage");
	printf(": openlog <command> [options] ...\n");
	printf("Commands:\n");
	printf("	start	Starts the main logging process\n");
	printf("	stop	Stops the main logging process\n");
	printf("	init	Creates a new log for a process\n");
	printf("	raise	Raises an event in the log\n");
	printf("	help	Displays help on a given command\n");
	printf("	license	Displays the OpenLog license\n");
	printfc(COLOR_LAQUA, "See 'openlog help <command>' for help on a specific command.\n");
}

void showLicense()
{
	FILE* f;
	int fLen;
	char c;
	int pos;
	
	f = fopen("LICENSE", "rb");
	if (!f)
	{
		printStatus("Failed to open 'LICENSE' file.", STATUS_ERROR);
		return;
	}
	
	fseek(f, 0, SEEK_END);
	fLen = ftell(f);
	rewind(f);
	
	banner();
	printf("\n");
	
	for (pos = 0; pos < fLen; pos++)
	{
		fread(&c, sizeof(char), 1, f);
		putchar(c);
	}
	
	fclose(f);
}

void showStartInfo()
{
	
}

void showStopInfo()
{
	
}

void showInitInfo()
{
	banner();
	printfc(COLOR_LGREEN, "Usage");
	printf(": openlog init <log name>\n");
	printf("Initialises a new log file at LOGNAMEXXXX.OLG\n");
}

void showRaiseInfo()
{
	
}

void showHelp(int argc, char* argv[])
{
	char* command;
	char dispStr[256];
	
	if (argc < 3)
	{
		usage();
		return;
	}
	
	command = argv[2];
	command[strlen(argv[2])] = '\0';
	strupper(command);
	
	if (!strcmp(command, "START"))
		showStartInfo();
	else if (!strcmp(command, "STOP"))
		showStopInfo();
	else if (!strcmp(command, "INIT"))
		showInitInfo();
	else if (!strcmp(command, "RAISE"))
		showRaiseInfo();
	else
	{
			sprintf(dispStr, "\'%s\' is not a valid command.", command);
			printStatus(dispStr, STATUS_ERROR);
			printfc(COLOR_LAQUA, "See \'openlog help\' for a list of valid commands.\n");
	}
}