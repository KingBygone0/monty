#include "monty.h"

/**
 * divide - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int results;

	(void)arg;

	if (!stack || !*stack || !(*stack)->next || (*stack)->n == 0)
	{
		if ((*stack)->n == 0)
		fprintf(stderr, "L%u: division by zero\n", line_number);
		else
		{
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	results = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = results;
}

/**
 * multiply - Multiplies the second top element of stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	int results;

	(void)arg;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	results = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = results;
}
