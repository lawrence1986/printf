#include "main.h"
/**
* fetch_flags - Calculates active flags
* @format: Formatted string in which to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int fetch_flags(const char *format, int *i)
{
/* - + 0 # ' ' */
/* 1 2 4 8 16 */
int j = 0, curr_i = *i + 1;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
F_SPACE, 0};
while (format[curr_i] != '\0')
{
while (FLAGS_CH[j] != '\0')
{
if (format[curr_i] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
j++;
}
if (FLAGS_CH[j] == 0)
break;
curr_i++;
}
*i = curr_i - 1;
return (flags);
}
