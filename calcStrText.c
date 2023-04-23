#include "main.h"

/**
 * calcStrText - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @k: List of arguments to be printed.
 * @file: list of arguments.
 *
 * Return: width.
 */
int calcStrText(const char *format, int *k, va_list file)
{
	int curr_k;
	int width = 0;
curr_k = *k + 1;

while (format[curr_k] != '\0')
{
	if (is_digit(format[curr_k]))
	{
		width *= 10;
		width += format[curr_k] - '0';
	}
	else if (format[curr_k] == '*')
	{
		curr_k++;
		width = va_arg(file, int);
		break;
	}
	else
	{
		break;
	}

}

*k = curr_k - 1;

return (width);
}
