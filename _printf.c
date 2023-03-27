#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void print_str(char *str);
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
			putchar(format[i]);
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					putchar(va_arg(args, int));
					i++;
					break;
				case 's':
					print_str(va_arg(args, char *));
					i++;
					break;
				case '%':
					putchar('%');
					i++;
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
void print_str(char *str)
{
	while (*str)
	{
		putchar(*str);
		str++;
	}
}
