#include "monty.h"

/**
  * free_stack - frees a doubly linked list
  * @head: pointer to the head of the stack
  */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}

}
