#include "monty.h"

/**
  * _pint - prints the value at the top of the stack
  * @stack: Pointer to the head of the stack
  * @line_number: Line number in the file
  */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (!stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
	temp = temp->next;

}
