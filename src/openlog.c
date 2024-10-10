#include <stdio.h>

#include "openlog.h"
#include "color.h"
#include "help.h"
#include "util.h"
#include "structure.h"

// Returns an integer identifying the supplied command. openlog.h for definitions.
int getCommand(int argc, char* argv[])
{
	char* command;
	if (argc < 2) return COMMAND_ERROR;
	command = argv[1];
	command[strlen(argv[1])] = '\0';
	strupper(command);  // Make the string uppercase for comparision
	
	// Select the correct command
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
	else if (!strcmp(command, "LICENSE"))
		return COMMAND_LICENSE;
	return COMMAND_NONE;
}

// Fill a LOG_HEADER with default data
void fillLogHeader(LOG_HEADER* lh)
{
	strncpy(lh->id, _ID, 4);
	lh->minorVersion = _MIN_VER;
	lh->majorVersion = _MAJ_VER;
	lh->nEvents = 0;
	lh->eventsOffset = sizeof(LOG_HEADER);
	lh->attributes = 0;
	memset(lh->nextFile, 0, 12);
}

// Creates and initialises a log file
void initialiseLog(int argc, char* argv[])
{
	char* logName;
	char  logFileName[13];
	char dispStr[256];
	FILE* f;
	LOG_HEADER* lh;
	int i;
	
	// No log name
	if (argc < 3)
	{
		printStatus("The sytnax of the command is incorrect.", STATUS_ERROR);
		printfc(COLOR_LAQUA, "See \'openlog help init\' for help on this command.\n");
		return;
	}
	
	// Initialise log name
	logName = (char*)malloc(sizeof(char*) * 9);
	memcpy(logName, argv[2], (strlen(argv[2]) >= 4) ? 4 : strlen(argv[2]));
	
	// Fill with zeroes
	for (i = ((strlen(argv[2]) >= 4) ? 4 : strlen(argv[2])); i < 8; i++)
	{
		logName[i] = '0';
	}
	
	logName[8] = '\0';
	strupper(logName);

	// Append ".OLG"
	memcpy(logFileName, logName, (strlen(logName) > 8) ? 9 : strlen(logName) + 1);
	strncat(logFileName, ".OLG", 4);
	logFileName[12] = '\0';
	
	free(logName);
	
	sprintf(dispStr, "Creating log file in \"%s\"...", logFileName);
	printStatus(dispStr, STATUS_INFO);
	
	// Can we open the log file?
	if (faccess(logFileName, "wb"))
		f = fopen(logFileName, "wb");
	else 
	{
		printStatus("Failed to open log file for writing.", STATUS_ERROR);
		return;
	}

	// Initialise and write log header
	lh = (LOG_HEADER*)malloc(sizeof(LOG_HEADER));
	fillLogHeader(lh);
	
	fwrite(lh, sizeof(LOG_HEADER), 1, f);
	
	fclose(f);
	free(lh);
	
	printStatus("Successfully initialised log file.", STATUS_INFO);
}

// Main application entry point
int main(int argc, char* argv[])
{
	int command;
	char dispStr[256];
	
	if (argc < 2)
	{
		usage();
		return 0;
	}
	
	command = getCommand(argc, argv);
	
	switch (command)
	{
		case COMMAND_NONE:
			sprintf(dispStr, "\'%s\' is not a valid command.", argv[1]);
			printStatus(dispStr, STATUS_ERROR);
			printfc(COLOR_LAQUA, "See \'openlog help\' for a list of valid commands.\n");
			return 1;
		case COMMAND_HELP:
			showHelp(argc, argv);
			return 0;
		case COMMAND_LICENSE:
			showLicense();
			return 0;
		case COMMAND_INIT:
			initialiseLog(argc, argv);
			return 0;
	}
	return 0;
}