#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int print_str(char *str);
/**
 *_printf - print output according to given format.
 *@format: char string.
 *Return: integer number of chars printed excluding null terminal.
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			continue;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					putchar(va_arg(args, int));
					i++;
					break;
				case 's':
					i+=print_str(va_arg(args, char *));
					break;
				case '%':
					putchar('%');
					i++;
					break;
				default:
					break;
			}
		}
		i++;
	}
	va_end(args);
	return (i);
}
/**
 * print_str - print given string.
 * @str : char pointer.
 * Return: void
 */
int print_str(char *str)
{
	int i = 0;

	for (i = 0; *str; str++,i++)
	{
		putchar(*str);
	}
	return (i);
}
