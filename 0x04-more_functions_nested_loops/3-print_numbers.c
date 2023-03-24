#include "main.h"

/**
 * print_numbers - print number upto nine
 *
 * Return: void
 */

void print_numbers(void)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		_putchar(i + '0');
		i++;
	}
	_putchar('\n');
}
