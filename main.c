#include "monty.h"

int stack[SIZE];
int top = -1;
/**
  * push - a function pushes an element to the stack
  * @value: an integer to push
  */
void push(int value)
{
	if (top == SIZE - 1)
	{
		fprintf(stderr, "Error: Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = value;
}

/**
  * pall - a function prints all the values on the stack,
  * starting from the top of the stack
  */
void pall()
{
	int i;
	for (i = top; i >= 0; i--)
		printf("%d\n", stack[i]);
}
