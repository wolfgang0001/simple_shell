#include "simple.h"

/**
 * dir_search - checks all directories stored in path_tokens for a
 * specific file. 
 * Author: kingsley
 * @path_tokens: Pointer to an array of str showing the dif
 * paths contained in the PATH environmental var.
 * @command: standing as a command. For e.g ls, echo, pwd, /bin/ls etc.
 * Return: Upon success a string with the upper most directory containing
 * the command file. Otherwise returns NULL.
 */
char *dir_search(char **path_tokens, char *command)
{
	int l, m;
	char *cwd;
	char *buf;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (NULL);
	if (command[0] == '/')
		command = command + 1;
	for (l = 0; path_tokens[l] != NULL; l++)
	{
		m = chdir(path_tokens[l]);
		if (m == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		m = stat(command, &stat_buf);
		if (m == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_tokens[l]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * f_paths - lokks for  the index of an environmental var.
 * Author: kingsley
 * @string: The envir.. var which needs to be found.
 * Return: Upon success returns the index of the environ.. var.
 * otherwise returns -1.
 */
int f_paths(char *string)
{
	int count;
	int length;
	int j;

	length = str_len(string);
	for (count = 0; environ[count] != NULL; count++)
	{
		for (j = 0; j < length; j++)
		{
			if (environ[count][j] != string[j])
				break;
		}
		if (j == length && environ[count][j] == '=')
			return (count);
	}
	return (-1);
}

/**
 * b_path - Combines two str one standing as the path directory and
 * one standing as  the command file.
 * Author: kingsley
 * @dir: Represents a directory in the path.
 * @com: Represents a file in a directory of the path.
 * Return: Upon success a string representing the full path of a command.
 * Otherwise NULL.
 */
char *b_path(char *dir, char *com)
{
	int i, j;
	int dir_length;
	int command_length;
	int length;
	char *b;

	if (dir == NULL || com == NULL)
		return (NULL);
	dir_length = str_len(dir) + 1;
	command_length = str_len(com) + 1;
	length = dir_length + command_length;

	b = malloc(sizeof(char) * length);
	if (b == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		for (j = 0; dir[j] != '\0'; j++, i++)
			b[i] = dir[j];
		b[i] = '/';
		i++;
		for (j = 0; com[j] != '\0'; j++, i++)
			b[i] = com[j];
	}
	b[--i] = '\0';
	return (b);
}

/**
 * tokenize_path - Separates a str standing as  paths as an array
 * of strs contining the path dirs.
 * Author: kingsley
 * @indx: Index of the path in the environ.. var.
 * @string: str to separate and tokenize.
 * Return: Upon success a NULL terminated array of pointer to strings.
 * Otherwise returns NULL. Note!: Do not forget to free alocated
 * memory on receiving function or when possible.
 */
char **tokenize_path(int indx, char *string)
{
	char *env_var;
	int token_count;
	const char *delim = ":\n";
	char **path_tokens;
	int len;

	len = str_len(string);
	token_count = 0;
	/*Moving the pointer len of str plus = sign*/
	env_var = environ[indx] + (len + 1);
	path_tokens = token_interface(env_var, delim, token_count);
	if (path_tokens == NULL)
		return (NULL);

	return (path_tokens);
}

/**
 * p_find - This response cases for functions that will be able to
 * find the full path of a program.
 * @com: Represents a command. For example ls, echo, pwd, etc.
 * Return: Upon sucess a string with the full path of the program.
 * for example /bin/ls, /bin/echo, etc. Otherwise returns NULL.
 */
char *p_find(char *com)
{
	char *strings = "PATH";
	char *cons;
	char **p_tokens;
	int index;
	char *dir;

	index = f_paths(strings);
	p_tokens = tokenize_path(index, strings);
	if (p_tokens == NULL)
		return (NULL);

	dir = dir_search(p_tokens, com);
	if (dir == NULL)
	{
		double_free(p_tokens);
		return (NULL);
	}

	cons = b_path(dir, com);
	if (cons == NULL)
	{
		double_free(p_tokens);
		return (NULL);
	}

	double_free(p_tokens);

	return (cons);
}
