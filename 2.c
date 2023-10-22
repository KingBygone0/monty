#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *topNode;

	/*(void)arg;*/

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	topNode = *stack;
	*stack = topNode->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(topNode);
}
