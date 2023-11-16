#include "simple.h"

/**
 * print_number - This prints an unsigned num
 * Author: kingslei
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_number(int num)
{
	int divide;
	int len;
	unsigned int number;

	divide = 1;
	len = 0;

	number = num;

	for (; number / divide > 9; )
		divide *= 10;

	for (; divide != 0; )
	{
		len += put_char('0' + number / divide);
		number %= divide;
		divide /= 10;
	}

	return (len);
}
