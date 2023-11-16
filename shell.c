#include "simple.h"

/**
 * main - This is the entry point for the program.
 * Author: kingsley
 * @pa: Number of Argument passed to the executable file. In the case
 * this variable will not be used.
 * @name: The name of the program.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int pa, char **name)
{
	char *line;
	size_t size;
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;
		line = NULL;
		size = 0;
		parse_line(line, size, command_counter, name);

	} while (1);

	return (0);
}
