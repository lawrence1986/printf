#include <unistd.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @d: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned,
 */


int _putchar(char d)
{
	return (write(1, &d, 1));
}
