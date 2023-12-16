#include "main.h"
/**
 * handlespaceN - handles space entered in prompt
 * @input: array of characters
 *
 * Return: returns 1 if successful and 0 if not
 */
int handlespaceN(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (!(input[i] == ' ' || input[i] == '\t'|| input[i] == '\n' || input[i] == '\v' || input[i] == '\f' || input[i] == '\r'))
			break;
	}
	if (input[i] == '\0')
	{
		return (1);
	}
	return (0);
}
