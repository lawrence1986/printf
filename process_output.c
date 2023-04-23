#include "main.h"

/*** WRITE HANDLE ***/
/**
* handle_write_char - Prints a string
* @d: char types.
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/
int process_output(char d, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int k = 0;
	char padding_value = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	padding_value = '0';
	buffer[k++] = d;
	buffer[k] = '\0';

	if (width > 1)

	buffer[1024 - 1] = '\0';
		for (k = 0; k < width - 1; k++)
		buffer[1024 - k - 2] = padding_value;

		if (flags & F_MINUS)
		return (write(1, &buffer[0], 1) +
		write(1, &buffer[1024 - k - 1], width - 1));
		else
		return (write(1, &buffer[1024 - k - 1], width - 1) +
		write(1, &buffer[0], 1));

		return (write(1, &buffer[0], 1));
}
/*** WRITE NUMBER ***/
/**
* write_number - Prints a string
* @is_negative: Lista of arguments
* @ind: char types.
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/
	int print_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 1024 - ind - 1;
	char padding_value = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	padding_value = '0';
	if (is_negative)
	extra_ch = '-';
	else if (flags & F_PLUS)
	extra_ch = '+';
	else if (flags & F_SPACE)
	extra_ch = ' ';

	return (print_num(ind, buffer, flags, width, precision,
	len, padding_value, extra_ch));
}

/**
* write_num - Write a number using a bufffer
* @ind: Index at which the number starts on the buffer
* @buffer: Buffer
* @flags: Flags
* @width: width
* @prec: Precision specifier
* @len: Number length
* @padding_value: Pading char
* @extra_d: Extra char
*
* Return: Number of printed chars.
*/
	int print_num(int ind, char buffer[],
	int flags, int width, int prec,
	int len, char padding_value, char extra_d)
{
	int k, padding_value_start = 1;

	if (prec == 0 && ind == 1024 - 2 && buffer[ind] == '0' && width == 0)
	return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == 1024 - 2 && buffer[ind] == '0')
	buffer[ind] = padding_value = ' ';
	if (prec > 0 && prec < len)
	padding_value = ' ';
	while (prec > len)
	{
		buffer[--ind] = '0', len++;
	}
	if (extra_d != 0)
	len++;

	if (width > len)
	{
	for (k = 1; k < width - len + 1; k++)
	buffer[k] = padding_value;
	buffer[k] = '\0';
	if (flags & F_MINUS && padding_value == ' ')
	if (extra_d)
	buffer[--ind] = extra_d;
	return (write(1, &buffer[ind], len) + write(1, &buffer[1], k - 1));
	else if (!(flags & F_MINUS) && padding_value == ' ')

	if (extra_d)
	buffer[--ind] = extra_d;
	return (write(1, &buffer[1], k - 1) + write(1, &buffer[ind], len));
	else if (!(flags & F_MINUS) && padding_value == '0')
	if (extra_d)
	buffer[--padding_value_start] = extra_d;
	return (write(1, &buffer[padding_value_start], k - padding_value_start) +
	write(1, &buffer[ind], len - (1 - padding_value_start)));
	}
	if (extra_d)
	buffer[--ind] = extra_d;
	return (write(1, &buffer[ind], len));
}
/**
* write_unsgnd - Writes an unsigned number
* @is_negative: Number indicating if the num is negative
* @ind: Index at which the number starts in the buffer
* @buffer: Array of chars
* @flags: Flags specifiers
* @width: Width specifier
* @precision: Precision specifier
* @size: Size specifier
*
* Return: Number of written chars.
*/
	int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = 1024 - ind - 1, k = 0;
	char padding_value = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == 1024 - 2 && buffer[ind] == '0')
	return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < len)

	padding_value = ' ';
}
	for (; precision > len; len++)
	{
	buffer[--ind] = '0';
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	padding_value = '0';

	if (width > len)

	int k = 0;

	while (k < width - len)
	{
	buffer[k] = padding_value;
	k++;
	}
	buffer[k] = '\0';
	{
	if (flags & F_MINUS)
	}
	/* Assign extra char to left of buffer [buffer>padd] */
	return (write(1, &buffer[ind], len) + write(1, &buffer[0], k));
	}
	else
	{
	/* Assign extra char to left of padding [padd>buffer] */
	return (write(1, &buffer[0], k) + write(1, &buffer[ind], len));
	}
}

return (write(1, &buffer[ind], len));

/**
* write_pointer - Write a memory address
* @buffer: Arrays of chars
* @ind: Index at which the number starts in the buffer
* @len: Length of number
* @width: Width specifier
* @flags: Flags specifier
* @padding_value: Char representing the padding
* @extra_d: Char representing extra char
* @padding_value_start: Index at which padding should start
*
* Return: Number of written chars.
*/
	int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char padding_value, char extra_d,
	int padding_value_start)
{
	int k = 3;

	if (width > len)
	{
		while (k < width - len + 3)
		{
			buffer[k] = padding_value;
			k++;
		}
		buffer[k] = '\0';

		if (flags & F_MINUS && padding_value == ' ')
{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_d)
				buffer[--ind] = extra_d;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], k - 3));
		}
		else if (!(flags & F_MINUS) && padding_value == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_d)
				buffer[--ind] = extra_d;
			return (write(1, &buffer[3], k - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && padding_value == '0')
		{
			if (extra_d)
			buffer[--padding_value_start] = extra_d;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_value_start], k - padding_value_start) +
				write(1, &buffer[ind], len - (1 - padding_value_start) - 2));
		}
	}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_d)
buffer[--ind] = extra_d;
return (write(1, &buffer[ind], 1024 - ind - 1));
}
}
