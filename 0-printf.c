#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: the number of character printed (excluding the null byte used
 * to end output of strings
 */

int _printf(const char *format, ...)
{
	va_list(_printf_args);
	va_start(_printf_args, format);
	int count;

	va_end();
	return (count);
}
