#include "main.h"
/**
 * _putchar - prints a character to stdout
 * @character: character to be printed in the stdout
 */
void _putchar(char character)
{
	write(1, &character, 1);
}

/**
 * _printString - prints a string to stdout
 * @string: points to a string
 */
void _printString(const char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}

/**
 * _strlen - prints the length of a string
 * @string: string whose length would be determined
 *
 * Return: returns the length
 */
size_t _strlen(const char *string)
{
	size_t len;

	len = 0;
	while (*string != '\0')
	{
		len++;
		string++;
	}
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: points to first string to compare
 * @s2: points to second string to compare
 *
 * Return: returns 0 if strings are equal
 * and any other value if they are not
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/**
 * _strdup - duplicates a string
 * @string: string to be duplicated
 *
 * Return: Null if failed and pointer
 * to the duplicated string if successful
 */
char *_strdup(const char *string)
{
	size_t i;

	size_t length = _strlen(string);
	char *copy = (char *)malloc(length + 1);

	if (copy == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
		copy[i] = string[i];
	}

	return (copy);
}
