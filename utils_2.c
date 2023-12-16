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
		if (!(input[i] == ' ' || input[i] == '\t'
					|| input[i] == '\v' || input[i] == '\f' || input[i] == '\r'))
			break;
	}
	if (input[i] == '\0')
	{
		_printString("$ ");
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
	} else
	{
		/** Recursively print each digit **/
		_printInteger(value / 10);
		/** Print the current digit if it is non-zero**/
		if (value % 10 != 0 || value / 10 != 0)
		{
			_putchar('0' + value % 10);
		}
	}
}
/**
 * _startshelln - begins simple shell program
 * for non interactive mode
 */
void _startshellN(void)
{
	ssize_t bytes;
	char **argv;
	char *token, *token_copy, *input;
	int token_count, index;
	size_t len;

	input = token_copy = token = NULL;
	len = index = token_count = 0;

	while ((bytes = getline(&input, &len, stdin) != -1))
	{
		if (handlespaceN(input))
			continue;
		/** Handles tokenization**/
		argv = _tokenize(input, token, token_copy, &token_count, &index);
		/** Handles exit built-in  **/
		_exitshell(argv, input, index);
		/** Handles env built-in non interactive **/
		if (_strcmp(argv[0], "env") == 0)
		{
			_printenvN(argv, token_copy, &token_count, &index);
			continue;
		}
		/** Handles fork for non interractive **/
		_forkN(argv, &index, &token_count);
	}
	free(input);
}
/**
 * _forkn - begins the fork system call for
 *
 * @argv: array of strings
 * @index: total number of strings including NULL
 * @token_count: total number of tokens
 * @token_copy: duplicate of token.
 */
void _forkN(char **argv, int *index, int *token_count)
{
	pid_t pid;
	int b;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if ((execve(argv[0], argv, NULL) == -1))
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	for (b = 0; b < *index; b++)
	{
		free(argv[b]);
	}

	free(argv);
	*index = 0;
	*token_count = 0;
}
/**
 * _printenvN - prints environment variables
 * in non interactive mode
 * @argv: pointer to an array of strings
 * @index: variable that holds the total
 * number of element in the array
 * @token_copy: duplicate array of characters
 * @token_count: total number of tokens
 *
 * Return: returns 1 if successful or 0 if not
 */
void _printenvN(char **argv, char *token_copy, int *token_count, int *index)
{
	char **env;
	int b;

	env = environ;
	while (*env != NULL)
	{
		_printString(*env);
		_putchar('\n');
		env++;
	}
	for (b = 0; b < *index; b++)
	{
		free(argv[b]);
	}
	free(argv);
	free(token_copy);
	*token_count = 0;
	*index = 0;
	env = environ;
	_printString("$ ");
}
