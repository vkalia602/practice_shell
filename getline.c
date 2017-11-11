#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	char *buffer;
	size_t size = 5;

	buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
		return (-1);
	printf("$ ");
	getline(&buffer, &size, stdin);
	printf("\n%s", buffer);
	return (0);
}
