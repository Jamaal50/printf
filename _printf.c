#include "main.h"

void print_buff(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);
/*************** write(1, &format[i], 1); **********/
			printed_chars++;
		}
		else
		{
			print_buff(buffer, &buff_ind);
			flags = use_flags(format, &i);
			width = use_width(format, &i, args);
			precision = use_precision(format, &i, args);
			size = use_size(format, &i);
			i++;
			printed = run_print(format, &i, args, buffer,
					       flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buff - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
