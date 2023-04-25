#include "main.h"
/**
* dataSize - Calcs size to cast the arg
* @format: Formatted string in which to print the arguments
* @i: List of args to be printed.
*
* Return: prec
*/
int dataSize(const char *format, int *i)
{
	int curr_i = *i;
	int size = 0;

	if (format[curr_i] == 'l')
	{
		size = S_LONG;
	}
	else if (format[curr_i] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = curr_i - 1;
	}
	else
	{
		*i = curr_i;
	}
return (size);
}
