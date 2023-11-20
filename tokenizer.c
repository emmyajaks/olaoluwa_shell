#include "shell.h"

/**
 * tokenizer - tokenize a string into an array of tokens
 * @line: the string to tokenize
 * Return: An array of tokens
 */
char **tokenizer(char *line)
{
	int i = 0, j = 0;
	char *token, *tmp, **array = NULL;
	
	if (!line)
		return NULL;
	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (!token)
	{
		free(line);
		free(tmp);
		tmp = line = NULL;
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);
	tmp = NULL;
	array = malloc(sizeof(char *) * (j + 1));
	if (!array)
	{
		free(line);
		free(tmp);
		tmp = line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		array[i++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	array[i] = NULL;
	free(line), line = NULL;
	
	return (array);
}