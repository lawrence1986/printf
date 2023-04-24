#include "main.h"

/**
 * calcStrText - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @file: list of arguments.
 *
 * Return: width.
 */
int calcStrText(const char *format, int *i, va_list file)
{
	int curr_i = *i + 1;
	int width = 0;

while (format[curr_i] != '\0')
{
	if (is_digit(format[curr_i]))
	{
		width *= 10;
		width += format[curr_i] - '0';
	}
	else if (format[curr_i] == '*')
	{
		curr_i++;
		width = va_arg(file, int);
		break;
	}
	else
	{
		break;
	}

}

*i = curr_i - 1;

return (width);
}
