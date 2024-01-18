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
	instruction_t instructions[] = {
					{"push", _push},
					{"pall", _pall},
					{"pint", _pint},
					{NULL, NULL}
							};
	int i, found = 0;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(command, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			found = 1;
			break;
		}
	}

	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}
