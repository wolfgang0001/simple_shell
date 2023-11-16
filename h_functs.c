#include "simple.h"

/**
 * exec_error - This handles exec errors.
 * Author: kingsley
 * @av: The name of the program running the shell.
 * @count: Keeps track of how many commands have been entered.
 * @tmp_command: The command that filed.
 */

void exec_error(char *av, int count, char *tmp_command)
{
	error_printing(av, count, tmp_command);
	print_str(": ", 1);
	perror("");
	exit(1);
}

/**
 * str_len - This Cal the lenght of a string.
 * Author: kingsley
 * @string: Str that needs length to be found.
 * Return: Upon success returns the length of a string. otherwise 0.
 */
int str_len(char *string)
{
	int cont;

	if (string == NULL)
		return (0);
	for (cont = 0; string[cont] != '\0'; cont++)
		;
	return (cont);
}

/**
 * single_free - Will free a n amount of pointers to a string.
 * @n: The number of pointers to free.
 */
void single_free(int n, ...)
{
	int i;
	char *str;
	va_list a_list;

	va_start(a_list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(a_list, char*);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(a_list);
}


/**
 * double_free - Free double pointer vars.
 * Author: kingsley
 * @freed: The address of the elements that need to be freed.
 */
void double_free(char **freed)
{
	int inx;

	for (inx = 0; freed[inx] != NULL; inx++)
		free(freed[inx]);
	free(freed);
}


/**
 * error_printing -This handles error message when a comand is not found.
 * Author: kingsley
 * @count: This count and keeps track the num of commands run on the shell.
 * @av: The name of the program running the shell.
 * @command: The specific command not being found.
 */
void error_printing(char *av, int count, char *command)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_number(count);
	print_str(": ", 1);
	print_str(command, 1);
}
