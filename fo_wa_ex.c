#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};
	pid_t child_pid;
	int status, i = 0;

	while (i < 5)
	{
	child_pid = fork();
	if (child_pid < 0)
	{
		printf("Error");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	if (child_pid > 0)
	{
		child_pid = wait(&status);
		if (child_pid < 0)
		{
			printf("error");
			return (0);
		}
		printf("DONE");
	}
	i++;
	}
	return (0);
}
