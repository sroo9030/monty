#include "monty.h"

/**
  * push - Pushes an element to the stack
  * @stack: Pointer to the head of the stack
  * @line_number: Line number in the file
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;

	arg = strtok(NULL, " \n\t");
	if (!arg || (!isdigit(*arg) && *arg != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
