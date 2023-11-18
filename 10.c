#include "seel.h"

/**
* strLength - returns the length of a string.
* @str: pointer to the string.
* Return: length of the string.
*/
int strLength(char *str)
{
int length = 0;

if (!str)
return (0);

while (*str++)
{
length++;
}
return (length);
}

/**
* strDuplicate - duplicates a string.
* @str: String to be copied.
* Return: pointer to the duplicated string.
*/
char *strDuplicate(char *str)
{
char *result;
int length = 0;
if (str == NULL)
return (NULL);
while (*str++)
length++;
result = malloc(sizeof(char) * (length + 1));
if (!result)
return (NULL);
for (length++; length--;)
result[length] = *--str;
return (result);
}
/**
* strCompare - Compare two strings.
* @str1: String one, or the shorter.
* @str2: String two, or the longer.
* @count: Number of characters to be compared, 0 if infinite.
* Return: 1 if the strings are equals, 0 if the strings are different.
*/
int strCompare(char *str1, char *str2, int count)
{
int iterator;

if (str1 == NULL && str2 == NULL)
return (1);

if (str1 == NULL || str2 == NULL)
return (0);

if (count == 0) /* Infinite length */
{
if (strLength(str1) != strLength(str2))
return (0);
for (iterator = 0; str1[iterator]; iterator++)
{
if (str1[iterator] != str2[iterator])
return (0);
}
return (1);
}
else /* If there is a number of characters to be compared*/
{
for (iterator = 0; iterator < count; iterator++)
{
if (str1[iterator] != str2[iterator])
return (0);
}
return (1);
}
}

/**
* strConcat - Concatenates two strings.
* @str1: First string to be concatenated.
* @str2: Second string to be concatenated.
* Return: Pointer to the concatenated string.
*/
char *strConcat(char *str1, char *str2)
{
char *result = str1;

while (*str1)
str1++;
while (*str2)
*str1++ = *str2++;
*str1 = *str2;
return (result);
}

/**
* strReverse - Reverses a string.
* @str: pointer to the string.
* Return: void.
*/
void strReverse(char *str)
{
int i = 0, length = strLength(str) - 1;
char hold;

while (i < length)
{
hold = str[i];
str[i++] = str[length];
str[length--] = hold;
}
}

