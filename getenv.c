#include "shell.h"

/**
 * _getenv - get  the value of an environmental variable
 * @variable:the name of the variable environment
 * return: the valuue of the environmental variable
 */

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;
		
	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
	}
	return (NULL);
}