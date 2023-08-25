#include "main.h"

/*
 * _printf = my own printf
 * @format = format string
 * Return: number of characters printed to standard output
 **/

int _printf(const char *format, ...)
{

	int char_print = 0;
	int num_digits = 0;
	va_list arg_list;

	if (format == NULL)
	{
		return (-1);
	}
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

				if (str == NULL)
				{
					write(1, "(null)", 6);
					char_print += 6;
				}
				else
				{
					while (*str)
					{
						write(1, str, 1);
						char_print++;
						str++;
					}
				}
				else if (*format == 'd' || *format == 'i')
				{
					int num = va_arg(arg_list, int);
					int num_copy = num;
					int num_digits = 0;

					if (num == 0)
					{
						write(1, "0", 1);
						char_print++;
					}
					else
					{
						while (num_copy != 0)
						{
							num_copy /= 10;
							num_digits++;
						}
						char num_str[num_digits + 1];
						num_str[num_digits] = '\0';


						while (num != 0);
						{
							num_digits--;
							num_str[num_digits] = (num % 10) + '0';
							num /= 10;
						}
						write(1, num_str, num_digits);
						char_print += num_digits;
					}
					else
					{
						write(1, format - 1, 2);
						char_print += 2;
					}
				}
				format++;
			}

    va_end(arg_list);
    return (char_print);
}
