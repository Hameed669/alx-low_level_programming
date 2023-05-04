#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The unsigned long integer to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i;

	for (i = 0; i < (int)sizeof(unsigned long int) * 8 - 1; i++)
	{
		if (n >> (sizeof(unsigned long int) * 8 - 1 - i) == 1)
			break;
	}

	for (; i >= 0; i--)
	{
		if ((n & (mask << i)) == 0)
			_putchar('0');
		else
			_putchar('1');
	}
}
