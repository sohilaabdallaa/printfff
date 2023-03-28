#include "main.h"

/**
 * print_string - Print string
 * @list: list.
 *
 * Return: String length.
 */

int print_string(va_list list)
{
	char *str;
	int str_len;

	str = va_arg(list, char*);
	str_len = print((str != NULL) ? str : "(null)");

	return (str_len);
}
