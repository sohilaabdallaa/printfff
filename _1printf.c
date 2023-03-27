#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int main(void)
{
    char *name = "sohila";
    int count = 0; 
	count = _printf("char %% my name is %c\n", name[0]);
	count =  _printf("and my name is %s\n", name);
    	printf("first count of char = %d\n",count);
	printf("second count whole name = %d\n",count);
	return 0;
}
void print_str(char *str);
/**
 *_printf - print output according to given format.
 *@format: char string.
 *Return: integer number of chars printed excluding null terminal.
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					i++;
					break;
				case 's':
					print_str(va_arg(args, char *));
					count++;
					i++;
					break;
				case '%':
					putchar('%');
					count++;
					i++;
					break;
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
void print_str(char *str)
{ 
	while (*str)
	{
		putchar(*str);
		str++;
	}
}
