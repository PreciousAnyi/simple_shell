#include "main.h"
/**
 * handlespace - handles space entered in prompt
 * @input: array of characters
 *
 * Return: returns 1 if successful and 0 if not
 */
int handlespace(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (!(input[i] == ' ' || input[i] == '\t' || input[i] == '\n'
					|| input[i] == '\v' || input[i] == '\f' || input[i] == '\r'))
			break;
	}
	if (input[i] == '\0')
	{
		_printString("#cisfun$ ");
		return (1);
	}
	return (0);
}
/**
 * _printInteger - prints integer to stdout
 * @value: integer value to be printed
 */
void _printInteger(int value)
{
	if (value < 0)
	{
	_putchar('-');
	value = -value;
	}

	if (value == 0)
	{
		_putchar('0');
	}
	else
	{
		/** Recursively print each digit **/
		_printInteger(value / 10);
		_putchar('0' + value % 10);
	}
}
