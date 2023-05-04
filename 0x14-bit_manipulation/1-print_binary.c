#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The unsigned long integer to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int next;
	int i, count = 0;

	for (i = 63; i >= 0; i--)
	{
		next = n >> i;

		if (next & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
