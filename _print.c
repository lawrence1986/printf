#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i = 0, ln = 0, output_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list file;
	char buffer[IO_SIZE];

	if (format == NULL)
		return (-1);

	va_start(file, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == IO_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			output_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = fetch_flags(format, &i);
			width = calcStrText(format, &i, file);
			precision = set_dec_precision(format, &i, file);
			size = dataSize(format, &i);
			i++;
			ln = printHandler(format, &i, file, buffer,
				flags, width, precision, size);
			if (ln == -1)
				return (-1);
			output_chars += ln;
		}
		i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(file);
	return (output_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
