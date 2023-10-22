#include "monty.h"
char *arg = NULL;
/**
 * push - pushes an element onto the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	if (!stack || !arg || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = atoi(arg);
	newNode->prev = NULL;
	if (*stack)
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	else
	{
		newNode->next = NULL;
	}
	*stack = newNode;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	 stack_t *Current = *stack;

	 (void)line_number;

	while (Current)
	{
		printf("%d\n", Current->n);
		Current = Current->next;
	}
}
