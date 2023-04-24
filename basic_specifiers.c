#include "main.h"

/*** PRINT PTR ***/
/**
 * print_ptr - Prints the value of a pointer variable
 * @set: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_ptr(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padding_value = ' ';
	int ind = 1024 - 2, len = 2, padding_value_start = 1; /* length=2, for '0x' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(set, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[1024 - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_value_start = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[k], BUFF_SIZE - k - 1));*/
	return (write_pointer(buffer, ind, len,
		width, flags, padding_value, extra_c, padding_value_start));
}

/*** PRINT NON PRINTABLE ***/
/**
 * print_legible- Prints ascii codes in hexa of non printable chars
 * @set: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_legible(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *s = va_arg(set, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[i] != '\0')
	{
		if (is_outputed(s[i]))
			buffer[i + offset] = s[i];
		else
			offset += append_xd_code(s[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
/*** PRINT REVERSE ***/
/**
 * print_rev - Prints reverse string.
 * @set: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rev(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int i, figure = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(set, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char c = s[i];

		write(1, &c, 1);
		figure++;
	}
	return (figure);
}
/*** PRINT A STRING IN ROT13 ***/
/**
 * print_rot13str - Print a string in rot13.
 * @set: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13str(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int i, j;
	int figure = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(set, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == s[i])
			{
				x = out[j];
				write(1, &x, 1);
				figure++;
				break;
			}
		}
		if (!in[j])
		{
			x = s[i];
			write(1, &x, 1);
			figure++;
		}
	}
	return (figure);
}
