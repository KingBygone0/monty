#include "monty.h"

/**
 * nop - this function does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	(void)arg;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int results;

	(void)arg;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	results = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = results;
}
