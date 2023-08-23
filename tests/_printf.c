#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format)
		if (*format == '%' && format++)
		{
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					for (char *s = va_arg(args, char *); *s; s++, count++)
						putchar(*s);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					count++;
				if (*format)
				{ putchar(*format);
					count++;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
	va_end(args);
return (count);
}
