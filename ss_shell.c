#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main (void)
{
	char *buffer, *argv[5], *token;
	size_t size = 20;
	pid_t child_pid;
	int status, i = 0, j = 1, x = 0;

	buffer = malloc(20 * sizeof(char));
	if (buffer == NULL)
	{
		free (buffer);
		return (-1);
	}
	while (j)
	{
		printf("Sue_She_ll$ ");
		getline(&buffer, &size, stdin);
		token = strtok(buffer, " \n\t");
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		argv[i] = NULL;
		child_pid = fork();
		if(child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		if (child_pid > 0)
		{
			child_pid = wait(&status);
		}
		j++;
	}
	free(buffer);
	return (0);

}
