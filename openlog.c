#include <stdio.h>

void usage()
{
	printf("OpenLog - A cross-platform universal logging library\n");
	printf("Usage: openlog <command> [options] ...\n");
	printf("Commands:\n");
	printf("	start	Starts the main logging process\n");
	printf("	stop	Stops the main logging process\n");
	printf("	init	Creates a new log for a process\n");
	printf("	raise	Raises an event in the log\n");
	printf("	help	Displays help on a given command\n");
	printf("See 'openlog help <command>' for help on a specific command.\n");
	printf("See 'openlog help openlog' for more information.\n");
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		usage();
		return 0;
	}
	return 0;
}