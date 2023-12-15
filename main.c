#include "main.h"
/**
 * main - simple shell
 *
 * Return: returns zero
 */
int main(void)
{
	/** Checks for interactive and non interactive mode **/
	if (isatty(STDIN_FILENO))
	{
		_startshell();
	} else
	{
		_startshellN();
	}
	return (0);
}
