#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
extern char **environ;

char *findpath(char *argv)
{
	char *token;
	char keyword[] = "PATH";
	char *copy;
	int i = 0;

	while (environ[i] != NULL)
	{
		copy  = strdup(environ[i]);
		token = strtok(copy, "=");
		if (strcmp(token, keyword) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}

char *fix_token(char *argv, char *token)
{
	char *new_token;
	int i = 0, j = 0, total_strlen = 0;

	total_strlen = (strlen(argv)) + (strlen(token));
	printf("string length- %d \n", total_strlen);
	new_token = malloc(total_strlen * sizeof(char) + 2);
	if (new_token == NULL)
	{
		free(new_token);
		return (NULL);
	}
	while(token[i] != '\0')
	{
		new_token[i] = token[i];
		i++;
	}
	new_token[i] = '/';
	while(argv[j] != '\0')
	{
		new_token[i + 1] = argv[j];
		j++;
		i++;
	}
	new_token[i + 1] = '\0';
	return(new_token);
}

char *which(char *argv)
{
	char *dir;
	char *token, *new_token, *holder_token;
	struct stat st;
	int i = 0;

	dir = findpath(argv);
	dir = strdup(dir);
	token = strtok(dir, "=:");
	while (i < 10)
	{
		holder_token = token;
		new_token = fix_token(argv, holder_token);
		if(stat(new_token, &st) == 0)
		{
			return (new_token);
		}
		i++;
		token = strtok(NULL, "=:");
	}
	return (NULL);
}

int main(void)
{
	char *argv[] = {"ls", "-l", NULL};
	printf("First: %s\n", argv[0]);
	argv[0] = which(argv[0]);
	printf("Second: %s\n", argv[0]);
	execve(argv[0], argv, NULL);
	printf("Third: %s\n", argv[0]);
	return (0);
}
