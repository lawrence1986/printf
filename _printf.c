#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
unsigned int k, ln = 0, output_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list file;
	char buffer[1024];

	if (format == NULL)
		return (-1);

	va_start(file, format);

	while (format && format[k] != '\0')
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == 1024)
			{
				print_buffer(buffer, &buff_ind);
			}
			/* write(1, &format[i], 1);*/
			output_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &k);
			width = get_width(format, &k, file);
			precision = get_precision(format, &k, file);
			size = get_size(format, &k);
			++k;
			ln = printHandler(format, &k, file, buffer,
				flags, width, precision, size);
			if (ln == -1)
				return (-1);
			output_chars += ln;
		}
		k++;
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
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
