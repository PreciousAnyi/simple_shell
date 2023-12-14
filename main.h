#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

extern char **environ;
void _putchar(char character);
void _printString(const char *string);
size_t _strlen(const char *string);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *string);
void _exitshell(char **argv, char *input, int index);
void _printenv(char **argv, char *token, int *count, int *index);
char **_tokenize(char *input, char *token, char *token_copy,
		int *token_count, int *index);
void _fork(char **argv, int *index, int *token_count,
		char *token_copy, int line_count);
void _startshell(void);
int handlespace(char *input);
void _printInteger(int value);
#endif
