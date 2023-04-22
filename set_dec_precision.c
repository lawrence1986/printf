#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_clarity(const char *format, int *k, va_list file)
{
	int curr_k = *k + 1;
	int clarity = -1;

	if (format[curr_k] != '.')
		return (clarity);

	clarity = 0;
curr_k += 1;

while (format[curr_k] != '\0')
{
if (is_digit(format[curr_k]))
{
clarity *= 10;
clarity = clarity + format[curr_k] - '0';
}
else if (format[curr_k] == '*')
{
curr_k++;
clarity = va_arg(file, int);
break;
}
else
{
break;
}

curr_k++;
}

*k = curr_k - 1;

return (clarity);
}
