#include "shell.h"

/**
 * main - Simple shell function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (success)
 */
int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, idx = 0;
	(void)ac;
	    
	while (1)
	{
		line = read_line();
		if (line == NULL) /* Reached EOF (Ctrl + D) */
		{
			if (isatty(STDIN_FILENO))
			    write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		command = tokenizer(line);
		if (!command) 
			continue;

		if (ls_builtin(command[0]))
			handle_builtin(command, argv, &status, idx);
		else  
			status = _execute(command, argv, idx);
	}
}