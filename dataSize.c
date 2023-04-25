#include "main.h"

/**
* dataSize - Calcs size to cast argument
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
*
* Return: Size.
*/
int dataSize(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;

switch (format[curr_i])
{
case 'l':
size = S_LONG;
break;
case 'h':
size = S_SHORT;
break;
default:
*i = curr_i - 1;
break;
}

if (size != 0)
*i = curr_i;

return (size);
}

