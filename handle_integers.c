#include "main.h"

<<<<<<< HEAD
/** PRINT CHAR **/
=======
/*** PRINT CHAR ***/

>>>>>>> 6f0f38015ea31f294fd4a7c37148da2b81d556e1
/**
 * print_char - Prints a characater
 * @set: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	char z = va_arg(set, int);

return (handle_write_char(z, buffer, flags, width, precision, size));
}
/*** PRINT A STRING ***/
/**
 * print_string - Prints a string
 * @set: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, k;
	char *s = va_arg(set, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (k = width - len; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - len; k > 0; k--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}

	return (write(1, s, len));
}
/*** PRINT PERCENT SIGN ***/
/**
 * print_percent - Prints a percent sign
 * @set: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(set);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*** PRINT INT ***/
/**
 * print_int - Print int
 * @set: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 1024 - 2;
	int is_negative = 0;
	long int n = va_arg(set, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[k--] = '0';

	buffer[1024 - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_number(is_negative, k, buffer, flags, width, precision, size));
}

/*** PRINT BINARY ***/
/**
 * print_binary - Prints an unsigned number
 * @set: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list set, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, k, sum;
	unsigned int a[32];
	int figure;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(set, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (k = 1; k < 32; k++)
	{
		m /= 2;
		a[k] = (n / m) % 2;
	}
	for (k = 0, sum = 0, figure = 0; k < 32; k++)
	{
		sum += a[k];
		if (sum || k == 31)
		{
			char z = '0' + a[k];

			write(1, &z, 1);
			figure++;
		}
	}
	return (figure);
}
