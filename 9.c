#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = second->n % top->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
