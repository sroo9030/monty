#include "monty.h"

/**
  * _pall - Prints all the values on the stack
  * @stack: Pointer to the head of the stack
  * @line_number: Line number in the file
  */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
