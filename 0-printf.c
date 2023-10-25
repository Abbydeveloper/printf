#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _strlen - Return the length of a string
 * @s: string to return length
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: the number of character printed (excluding the null byte used
 * to end output of strings
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list _printf_args;
	va_start(_printf_args, format);

	if (format == NULL)
		return (-1);

	while(*format)
	{
		if (*format == '%')
		{
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
				char c = va_arg(_printf_args, int);

				count++;
				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str;
				int len;

				str = va_arg(_printf_args, char *);
				len = _strlen(str);

				count += len;
				write(1, str, len);
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
