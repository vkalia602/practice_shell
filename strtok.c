#include <stdio.h>
#include <string.h>

int main (void)
{
	char string[] = "Young dumb broke high school kids";
	char *token;

	token = strtok(string, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
