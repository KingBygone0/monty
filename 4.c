#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	int results;

	(void)arg;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	results = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number); /*Remove the top element*/
	(*stack)->n = results; /* Store the result in the remaining element*/
}
