#include "simple.h"

/**
 * builtin_chk - looks for the function correctly needed for execution.
 * Author: Kingsley
 * @strs:  Name of the function that is needed.
 * Return:n when sucess a pointer to a void function. Otherwise NULL.
 */
void (*builtin_chk(char *strs))(char *strs)
{
	int m;

	builtin_t buildin[] = {
		{"exit", exit_sh},
		{"env", envir_v},
		{"cd", chdir_cd},
		{NULL, NULL}
	};

	for (m = 0; buildin[m].built != NULL; m++)
	{
		if (_strcmp(strs, buildin[m].built) == 0)
		{
			return (buildin[m].f);
		}
	}
	return (NULL);
}

/**
 * envir_v - This print environmental variables in the current shell.
 * Author: kingsley
 * @line: A str argument for the input from the user.
 */
void envir_v(__attribute__((unused))char *line)
{
	int k;
	int l;

	for (k = 0; environ[k] != NULL; k++)
	{
		for (l = 0; environ[k][l] != '\0'; l++)
			write(STDOUT_FILENO, &environ[k][l], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}


/**
 * chdir_cd - This change working directory to the argument passed to cd.
 * when no Argument is passed it will change directory to HOME.
 * Authro: kingsley
 * @cd: A str representing the input from the user.
 */
void chdir_cd(char *cd)
{
	int index;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	param_array = token_interface(cd, delim, token_count);
	if (param_array[0] == NULL)
	{
		single_free(2, param_array, cd);
		return;
	}
	if (param_array[1] == NULL)
	{
		index = f_paths("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(param_array[1], "-") == 0)
		print_str(param_array[1], 0);

	else
		chdir(param_array[1]);
	double_free(param_array);
}

/**
 * exit_sh - This exits shell. After freeing allocated resources.
 * Author: kingsley
 * @para: A str input from the user.
 */
void exit_sh(char *para)
{
	free(para);
	print_str("\n", 1);
	exit(1);
}


/**
 * built_in - This checks for builtin functions.
 * Author: Kingsley
 * @com: An array of all parameter given to shell.
 * @line: A str input from the user.
 * Return: If function is found 0. Otherwise -1.
 */
int built_in(char **com, char *line)
{
	void (*build)(char *);

	build = builtin_chk(com[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", com[0]) == 0)
		double_free(com);
	build(line);
	return (0);
}
