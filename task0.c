#include "monty.h"

/**
 * push_func - pushes an element onto the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num;
	char *arg = strtok(NULL, " \t\n");

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);
	if (!num && num != 0)
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
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall_func - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *Current = *stack;

	(void)line_number;

	while (Current)
	{
		printf("%d\n", Current->n);
		Current = Current->next;
	}
}
