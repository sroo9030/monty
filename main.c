#include "monty.h"

/**
  * main - Monty interpreter main function
  * @ac: Argument count
  * @av: Argument array
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
  */
int main(int ac, char *av[])
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
	int found = 0, i;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (!file)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++, opcode = strtok(line, " $\n\t");
		if (!opcode || *opcode == '#')
			continue;
		found = 0;
		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number), found = 1;
			break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
