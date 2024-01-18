#include "monty.h"

/**
  * main - Monty interpreter main function
  * @ac: Argument count
  * @av: Argument array
  * Return: 0 on success
  */
int main(int ac, char *av[])
{
	FILE *file;
	char *line = NULL, *token;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, " $\t\n");
		if (!token || *token == '#')
			continue;
		if (token)
			cases(token, &stack, line_number);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
