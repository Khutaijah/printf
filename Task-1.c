#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/*
 * _printf = my own printf
 * @format = format string
 * Return: number of characters printed to standard output
 **/

/*int _printf(const char *format, ...)
{**/
	int char_print = 0;
	va_list arg_list;

	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(arg_list, int);
				char buffer[20]; /* Assuming a maximum of 20 characters for the number */

				int num_chars = snprintf(buffer, sizeof(buffer), "%d", num);
				write(1, buffer, num_chars);
				char_print += num_chars;
			}
		}
		format++;
	}

	va_end(arg_list);


	format++;

	return (char_print);

