#include "monty.h"

/**
  * cases - check the enterd command to be executed
  * @command: the command
  * @stack: Pointer to the head of the stack
  * @line_number: Line number in the file
  * Return: Alawys 0
  */
void cases(char *command, stack_t **stack, unsigned int line_number)
{
	if (strcmp(command, "push") == 0)
		push(stack, line_number);

	else if (strcmp(command, "pall") == 0)
		pall(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
		exit(EXIT_FAILURE);
	}
}
