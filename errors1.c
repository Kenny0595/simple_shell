#include "shell.h"

/**
 * _erratoi - transforms a string to an integer
 * @s: the string that will be transformed
 * Return: If there are no numbers in the string, return 0; otherwise, return -1 on error.
 * this code is written by KENNY and MBULA 
 * wishing my self goodluck
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter and return information struct
 * @estr: string with the error type provided
 * Return: If there are no numbers in the string, return 0; otherwise, return -1 on error.
 * this code is written by KENNY and MBULA 
 * wishing my self goodluck
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - The function returns a decimal (integer) number (in base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of printed char
 * this code is written by KENNY and MBULA 
 * wishing my self goodluck
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - itoa clone conversion function
 * @num: num
 * @base: base
 * @flags: arg  flags
 *
 * Return: string
 * this code is written by KENNY and MBULA 
 * wishing my self goodluck
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function substitutes the first occurrence of '#' with '0'
 * @buf: address of the string to be changed
 *
 * Return: Always 0;
 * this code is written by KENNY and MBULA 
 * wishing my self goodluck
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
