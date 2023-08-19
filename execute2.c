#include "shell.h"

/**
 * execute2 - execute the command line
 * @cmd: the command line
 * @argv: argument vector.
 * @envp: the environment argument.
 */
void execute2(char *cmd, char *argv[], char *envp[])
{
	int status;
	pid_t child;
	char *path;

	path = checker(cmd);
	if (path == NULL)
	{
		return;
	}
	child = fork();
	if (child == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execute(path, argv, envp);
	}
	else
	{
		wait(&status);
	}
	if ((path != NULL) && (path != cmd))
	{
		free(path);
		path  = NULL;
	}
}
