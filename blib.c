#include "simple.h"

/**
 * put_char - Writes a character to stdout
 * Aurthor: kingsley
 * @s: Character that will be written to stdout
 * Return: Upon success how many characters were written.
 */
int put_char(char s)
{
	return (write(1, &s, 1));
}

/**
 * _strcmp - compares two strings
 * Author: kingsley
 * @k1: First string
 * @k2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *k1, char *k2)
{
	int n;

	if (str_len(k1) != str_len(k2))
		return (-1);
	for (n = 0; k1[n] != '\0'; n++)
	{
		if (k1[n] != k2[n])
			return (-1);
	}
	return (0);
}

/**
 * print_str - This prints  str chara by character.
 * Author: kingsley
 * @string: If the string is NULL it will print (null)
 * @n_line: If integer is 0 a new line will be printed. Otherwise a new line
 * will not be printed.
 */
void print_str(char *string, int n_line)
{
	int m;

	if (string == NULL)
		string = "(null)";
	for (m = 0; string[m] != '\0'; m++)
		write(STDOUT_FILENO, &string[m], 1);
	if (n_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/**
 * _strdup - This create a copy of a str
 * Author: kingsley
 * @source: Contains the original string
 * Return: Gives back the copy of string
 */
char *_strdup(char *source)
{
	int i;
	int length;
	char *destination;

	length = str_len(source);
	destination = malloc(sizeof(char) * (length + 1));

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];
	destination[i] = '\0';
	return (destination);
}
