#include "monty.h"
/**
 * initializeStack - Initializes a stack_t stack
 * @stack: A double pointer to the stack_t stack
 */
void initializeStack(stack_t **stack)
{
	*stack = NULL;
}

/**
 * nop - Does nothing
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pop - Removes the top element from the stack and returns its value
 * @stack: A double pointer to the stack_t stack
 * @line_number: The line number
 * Return: The value of the popped element
 */
int pop(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	return (value);
}
