#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: the number of character printed
 */
int _printf(const char *format, ...)
{
	int count = 0, va_list _printf_args;

	va_start(_printf_args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			char c, *str, int len;

			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				count++;
				write(1, format, 1);
			}
			else if (*format == 'c')
			{
				c = va_arg(_printf_args, int);
				count++;
				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				str = va_arg(_printf_args, char *);
				str = (str == NULL) ? "(nul)" : str;
				count += _strlen(str);
				write(1, str, _strlen(str));
			}
		}
		else
		{
			count++;
			write(1, format, 1);
		}
		format++;
	}
	va_end(_printf_args);
	return (count);
}
