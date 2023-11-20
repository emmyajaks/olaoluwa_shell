#include "shell.h"

/**
 * read_line - read input line from the user
 * 
 * Return: return NULL on failure
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	read_len = getline(&line, &len, stdin);
	    
	if (read_len == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}