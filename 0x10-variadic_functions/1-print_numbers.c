#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - print number & new line
 * @separator: string
 * @n: numbers of element
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list ap;
unsigned int i;

va_start(ap, n);

for (i = 0; i < n; i++)
{
printf("%d", va_arg(ap, int));

if (separator != NULL && i != (n - 1))
{
printf("%s", separator);
}
}
putchar('\n');
va_end(ap);
}
