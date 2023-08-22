#include "main.h"

/*
 * _printf = my own printf
 * @format = format string
 * Return: number of characters printed to standard output
 **/

int _printf(const char *format, ...)
{

	int char_print = 0;

	va_list arg_list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	while (*format)
	{
		int str_len = 0;

		if (*format != '%')
	
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format  == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}

			else if (*format == 'c')
			{
				char c = va_arg(arg_list, int);

				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg_list, char*);

				while (str[str_len] != '\0')
				str_len++;
				write(1, str, str_len);
				char_print += str_len;
			}
		}
		format++;
	}
	va_end(arg_list);
	return (char_print);
	}
}
