#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, its all better now\n");
	}
	return (0);
}
