#include "main.h"
/**
 * _exitshell - exits the shell
 * @argv: pointer to an array of strings
 * @input: pointer to an array of characters
 * @index: variable that holds the total
 * number of element in the array
 */
void _exitshell(char **argv, char *input, int index)
{
	int b;

	if (argv[0] == NULL || _strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] == NULL)
		{
			free(input);
			for (b = 0; b < index; b++)
			{
				free(argv[b]);
			}
			free(argv);
			_printString("Exiting the shell.....");
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
	}
}
/**
 * _printenv - prints environment variables
 * @argv: pointer to an array of strings
 * @index: variable that holds the total
 * number of element in the array
 * @token_copy: duplicate array of characters
 * @token_count: total number of tokens
 *
 * Return: returns 1 if successful or 0 if not
 */
void _printenv(char **argv, char *token_copy, int *token_count, int *index)
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
/**
 * _tokenize - breaks array of characters into tokens
 * @input: array of characters
 * @token: pointer to an array of characters
 * @token_copy: token duplicate
 * @token_count: total number of tokens
 * @index: total number of string tokens including NULL
 *
 * Return: returns argv(an array of strings).
 */
char **_tokenize(char *input, char *token, char *token_copy,
		int *token_count, int *index)
{
	const char *delimeter;
	char **argv;

	delimeter = " \n";
	token_copy = _strdup(input);
	token = strtok(token_copy, delimeter);

	while (token != NULL)
	{
		*token_count += 1;
		token = strtok(NULL, delimeter);
	}

	argv = (char **)malloc((*token_count + 1) * sizeof(char *));
	if (argv == NULL)
		perror("error");

	token = strtok(input, delimeter);

	while (token != NULL)
	{
		argv[*index] = _strdup(token);
		*index += 1;
		token = strtok(NULL, delimeter);
	}
	argv[*index] = NULL;
	free(token_copy);
	return (argv);
}
/**
 * _fork - begins the fork system call
 * @argv: array of strings
 * @index: total number of strings including NULL
 * @token_count: total number of tokens
 * @token_copy: duplicate of token.
 */
void _fork(char **argv, int *index, int *token_count)
{
	pid_t pid;
	int status;
	int b;

	pid = fork();

	if (pid == 0)
	{
		if ((execve(argv[0], argv, NULL) == -1))
		{
			perror("./hsh");
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		wait(&status);
	}
	for (b = 0; b < *index; b++)
	{
		free(argv[b]);
	}

	free(argv);
	*index = 0;
	*token_count = 0;
	_printString("$ ");
}
/**
 * _startshell - begins simple shell program
 */
void _startshell(void)
{
	ssize_t bytes;
	char **argv;
	char *token, *token_copy, *input;
	int token_count, index;
	size_t len;

	input = token_copy = token = NULL;
	len = index = token_count = 0;

	_printString("$ ");
	while ((bytes = getline(&input, &len, stdin) != -1))
	{
		if (handlespace(input))
			continue;
		/** Handles tokenization**/
		argv = _tokenize(input, token, token_copy, &token_count, &index);
		/** Handles exit built-in  **/
		_exitshell(argv, input, index);
		/** Handles env built-in **/
		if (_strcmp(argv[0], "env") == 0)
		{
			_printenv(argv, token_copy, &token_count, &index);
			continue;
		}
		if ((execve(argv[0], argv, NULL) == -1))
		{
			perror("./hsh");
			exit(EXIT_SUCCESS);/** exit shell if command not found**/
		}
		/** Handles fork **/
		_fork(argv, &index, &token_count);
	}
	free(input);
}
