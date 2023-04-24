#include "main.h"

/*** WRITE HANDLE ***/
/**
* handle_write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/
int process_output(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padding_value = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	padding_value = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)

	buffer[IO_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
		buffer[IO_SIZE - i - 2] = padding_value;

		if (flags & F_MINUS)
		return (write(1, &buffer[0], 1) +
		write(1, &buffer[IO_SIZE - i - 1], width - 1));
		else
		return (write(1, &buffer[IO_SIZE - i - 1], width - 1) +
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
	int len = IO_SIZE - ind - 1;
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
* @extra_c: Extra char
*
* Return: Number of printed chars.
*/
	int print_num(int ind, char buffer[],
	int flags, int width, int prec,
	int len, char padding_value, char extra_c)
{
	int i = 1, padding_value_start = 1;

	if (prec == 0 && ind == IO_SIZE - 2 && buffer[ind] == '0' && width == 0)
	return (0);
	if (prec == 0 && ind == IO_SIZE - 2 && buffer[ind] == '0')
	buffer[ind] = padding_value = ' ';
	if (prec > 0 && prec < len)
	padding_value = ' ';
	while (prec > len)
	{
		buffer[--ind] = '0', len++;
	}
	if (extra_c != 0)
	len++;

	if (width > len)
	{
	for (i = 1; i < width - len + 1; i++)
		buffer[i] = padding_value;
	buffer[i] = '\0';
	if (flags & F_MINUS && padding_value == ' ')
	if (extra_c)
	buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
	}
	else if (!(flags & F_MINUS) && padding_value == ' ')
	{
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
	}
	else if (!(flags & F_MINUS) && padding_value == '0')
	if (extra_c)
	buffer[--padding_value_start] = extra_c;
	return (write(1, &buffer[padding_value_start], i - padding_value_start) +
	write(1, &buffer[ind], len - (1 - padding_value_start)));
	if (extra_c)
		buffer[--ind] = extra_c;
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
	int len = IO_SIZE - ind - 1, i = 0;
	char padding_value = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == IO_SIZE - 2 && buffer[ind] == '0')
	return (0);

	if (precision > 0 && precision < len)
	padding_value = ' ';

	for (; precision > len; len++)
	{
	buffer[--ind] = '0';
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	padding_value = '0';

	if (width > len)
{
	for (i = 0; i < width - len; i++)
	buffer[i] = padding_value;
	buffer[i] = '\0';

	if (flags & F_MINUS)
	{
	return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
	}
	else
	{
	return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
	}
}
return (write(1, &buffer[ind], len));
}
/**
* write_pointer - Write a memory address
* @buffer: Arrays of chars
* @ind: Index at which the number starts in the buffer
* @len: Length of number
* @width: Width specifier
* @flags: Flags specifier
* @padding_value: Char representing the padding
* @extra_c: Char representing extra char
* @padding_value_start: Index at which padding should start
*
* Return: Number of written chars.
*/
	int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char padding_value, char extra_c,
	int padding_value_start)
{
	int i = 3;

	if (width > len)
	{
		while (i < width - len + 3)
		{
			buffer[i] = padding_value;
			i++;
		}
		buffer[i] = '\0';
	if (flags & F_MINUS && padding_value == ' ')
	{
		buffer[--ind] = 'x';
		buffer[--ind] = '0';
		if (extra_c)
		{
			buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
	}
		else if (!(flags & F_MINUS) && padding_value == ' ')
		{
			buffer[--ind] = 'x', buffer[--ind] = '0';
		}
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && padding_value == '0')
		{
			if (extra_c)
				buffer[--padding_value_start] = extra_c;
			buffer[1] = '0', buffer[2] = 'x';
			return (write(1, &buffer[padding_value_start], i - padding_value_start) +
				write(1, &buffer[ind], len - (1 - padding_value_start) - 2));
		}
	}
buffer[--ind] = 'x', buffer[--ind] = '0';
if (extra_c)
	buffer[--ind] = extra_c;
return (write(1, &buffer[ind], IO_SIZE - ind - 1));
}
